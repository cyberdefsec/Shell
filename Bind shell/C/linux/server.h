#ifndef __SERVER_H__
#define __SERVER_H__

#include <netinet/in.h>

#include "execShell.h"

int connect_to_server(const char *addr, uint16_t port);

#endif
