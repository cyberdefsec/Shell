#ifndef __CONNECT_H__
#define __CONNECT_H__

#include <netinet/in.h>

#include "execShell.h"

#define OUTPUT_BUF 256

bool set_non_block_socket(int s, bool state);

int get_error_socket(int s, int *err);

int connect_to_server(int s, const struct sockaddr_in addr, int timeout);

int init_socket(void);

int set_addrs(struct sockaddr_in *sin, const char *addr, uint16_t port);

#endif
