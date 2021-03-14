#ifndef __CONNECT_H__
#define __CONNECT_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <winsock2.h>
#include <ws2tcpip.h>

int wsaInit(void);

SOCKET connectServer(const char *ipaddr, uint16_t port);

void closeServer(SOCKET s);

#endif // __CONNECT_H__
