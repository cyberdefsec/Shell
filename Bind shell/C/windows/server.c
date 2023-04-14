#include "server.h"

static char *get_addr_by_name(const char *name){
    struct hostent *hst = NULL;
    if((hst = gethostbyname(name)) != NULL)
        return inet_ntoa(*((struct in_addr*)hst->h_addr_list[0]));
    return NULL;
}

int wsa_init(void){
    WSADATA wsdata;
    if(WSAStartup(MAKEWORD(2, 2), &wsdata) != SOCKET_ERROR)
        return EXIT_SUCCESS;
    return SOCKET_ERROR;
}

SOCKET bind_server(const char *ipaddr, uint16_t port){
    SOCKET s = 0;
    SOCKET client = 0;
    struct sockaddr_in sin;
    memset(&sin, '\0', sizeof(sin));
    if((s = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0)) != SOCKET_ERROR){
        sin.sin_addr.S_un.S_addr = inet_addr(get_addr_by_name(ipaddr));
        sin.sin_family = AF_INET;
        sin.sin_port = htons(port);
        if(bind(s, (struct sockaddr*)&sin, sizeof(sin)) != SOCKET_ERROR){
            listen(s, 1);
            if((client = accept(s, NULL, NULL)) != SOCKET_ERROR)
                return client;
        }
    }
    return SOCKET_ERROR;
}

void close_server(SOCKET s){
    closesocket(s);
    WSACleanup();
}
