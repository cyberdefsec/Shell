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

#include "server.h"

static char *get_addr_by_name(const char *name){
    struct hostent *hst = NULL;
    if((hst = gethostbyname(name)) != NULL){
        return inet_ntoa(*((struct in_addr *)hst->h_addr_list[0]));
    }
    return NULL;
}

int bind_server(const char *addr, uint16_t port){
    int s = 0;
	int client = 0;
    struct sockaddr_in sin;
    if((s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) != EOF){
        sin.sin_family = AF_INET;
        sin.sin_port = htons(port);
        sin.sin_addr.s_addr = inet_addr(get_addr_by_name(addr));
        if(bind(s, (struct sockaddr*)&sin, sizeof(sin)) != EOF){
			listen(s, 1);
			if((client = accept(s, NULL, NULL)) != EOF)
				return client;
		}
    }
    return EOF;
}
