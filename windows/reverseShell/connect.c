#include "connect.h"

int wsaInit(void){
    WSADATA wsdata;
    if(WSAStartup(MAKEWORD(2, 2), &wsdata) != SOCKET_ERROR)
        return EXIT_SUCCESS;
    return SOCKET_ERROR;
}

SOCKET connectServer(const char *ipaddr, uint16_t port){
    SOCKET s;
    struct sockaddr_in sin;
    memset(&sin, '\0', sizeof(sin));
    if((s = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0)) != SOCKET_ERROR){
        sin.sin_addr.S_un.S_addr = inet_addr(ipaddr);
        sin.sin_family = AF_INET;
        sin.sin_port = htons(port);
        if(WSAConnect(s, (const struct sockaddr*)&sin, sizeof(sin), NULL, NULL, NULL, NULL) != SOCKET_ERROR)
            return s;
    }
    return SOCKET_ERROR;
}

void closeServer(SOCKET s){
    closesocket(s);
    WSACleanup();
}
