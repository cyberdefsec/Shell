#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <pwd.h>
#include <sys/types.h>

static pid_t child;

static void kill_child_process(int sig){
	if(sig == SIGPIPE)
        kill(child, SIGKILL);
}

static char *remove_crlf(char *str){
    int len = strlen(str) - 1;
    char *t = str;
    if(*t == '\r' || *t == '\n')
        return NULL;
    while((t[len] == '\n' || t[len] == '\r') && len > 0)
        len--;
    t[len + 1] = '\0';
    return str;

}

int changed_dirs(const char *path){
    struct passwd *pwd = NULL;
    if(path == NULL){
        pwd = getpwuid(getuid());
        return chdir(pwd->pw_dir);
    }
    return chdir(path);
}

int shell(char **args){
    int fd[2];
    signal(SIGPIPE, kill_child_process);
    if(pipe(fd) != EOF){
        switch(child = fork()){
            case EOF :
                close(fd[0]);
                close(fd[1]);
                break;
            case 0 :
                close(fd[0]);
                dup2(fd[1], STDOUT_FILENO);
                dup2(fd[1], STDERR_FILENO);
                close(fd[1]);
                if(execvp(args[0], args) == EOF)
                    return EOF;
                return EXIT_SUCCESS;
            default :
                close(fd[1]);
                return fd[0];
        }
    }
    return EOF;
}

char **parse_command(char *cmd){
    char **args = NULL;
    int row = 0;
    if(remove_crlf(cmd) == NULL)
        return NULL;
    if((args = (char**)malloc((row + 1) * sizeof(char*))) != NULL){
        args[row] = strtok(cmd, " ");
        while(args[row++] != NULL){
            args = (char**)realloc(args, (row + 1) * sizeof(char*));
            args[row] = strtok(NULL, " ");
        }
        return args;
    }
    return NULL;
}
