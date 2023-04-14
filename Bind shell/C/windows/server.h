#ifndef __CONNECT_H__
#define __CONNECT_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <winsock2.h>
#include <ws2tcpip.h>

int wsa_init(void);

SOCKET bind_server(const char *ipaddr, uint16_t port);

void close_server(SOCKET s);

#endif // __CONNECT_H__
