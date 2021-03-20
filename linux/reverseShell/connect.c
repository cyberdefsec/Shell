#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <net/if.h>

#include "connect.h"

static char *get_addr_by_name(const char *name){
    struct hostent *hst = NULL;
    if((hst = gethostbyname(name)) != NULL){
        return inet_ntoa(*((struct in_addr *)hst->h_addr_list[0]));
    }
    return NULL;
}

int set_addrs(struct sockaddr_in *sin, const char *addr, uint16_t port){
    char *ipaddr = NULL;
    if((ipaddr = get_addr_by_name(addr)) != NULL){
        sin->sin_family = AF_INET;
        sin->sin_port = htons(port);
        sin->sin_addr.s_addr = inet_addr(ipaddr);
        return EXIT_SUCCESS;
    }
    return EOF;
}

bool set_non_block_socket(int s, bool state){
    int flags = 0;
    if((flags = fcntl(s, F_GETFL, 0)) != EOF){
        if(state == true)
            flags |= O_NONBLOCK;
        else
            flags &= ~O_NONBLOCK;
        if(fcntl(s, F_SETFL, flags) != EOF)
            return true;
    }
    return false;
}

int get_error_socket(int s, int *err){
    socklen_t len = sizeof(*err);
    return getsockopt(s, SOL_SOCKET, SO_ERROR, err, &len);
}

int connect_to_server(int s, const struct sockaddr_in addr, int timeout){
    struct timeval tv;
    fd_set write_fd, except_fd;
    int active = 0;
    FD_ZERO(&write_fd);
    FD_SET(s, &write_fd);
    FD_ZERO(&except_fd);
    FD_SET(s, &except_fd);
    tv.tv_sec = timeout;
    tv.tv_usec = 0;
    if(connect(s, (const struct sockaddr*)&addr, sizeof(addr)) == EOF && errno != EINPROGRESS)
        return EOF;
    active = select(s + 1, NULL, &write_fd, &except_fd, &tv);
    switch(active){
        case EOF :
            return EOF;
        case 0 :
            errno = ETIMEDOUT;
            return EOF;
        default :
            if(FD_ISSET(s, &write_fd)){
                if(get_error_socket(s, &errno) == 0 && errno == 0)
                    return EXIT_SUCCESS;
                return EOF;
            }
            if(FD_ISSET(s, &except_fd)){
                perror("except");
                exit(0);
            }
    }
    return EOF;
}

int init_socket(void){
    return socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}
