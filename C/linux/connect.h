#ifndef __CONNECT_H__
#define __CONNECT_H__

#include <netinet/in.h>

#include "execShell.h"

int connect_to_server(const char *addr, uint16_t port);

#endif
