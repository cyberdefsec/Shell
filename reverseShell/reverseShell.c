#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "connect.h"

int main(int argc, char **argv){
    int sock;
    struct sockaddr_in sin;
    if(argc < 3 || set_addrs(&sin, argv[1], atoi(argv[2])) == EOF){
        fprintf(stderr, "Not found host\n");
        return EXIT_FAILURE;
    }
    while(true){
        sock = init_socket();
        set_non_block_socket(sock, true);
        if(connect_to_server(sock, sin, 60) == EOF)
            close(sock);
        else
            send_data(sock);
    }
    return 0;
}
