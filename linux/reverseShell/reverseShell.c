#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "connect.h"

int main(int argc, char **argv){
    int s;
    if(argc == 3){
	if((s = connect_to_server(argv[1], atoi(argv[2]))) != EOF)
            shell(s);
	close(s);
    }        
    return 0;
}
