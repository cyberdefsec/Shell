#include <stdio.h>
#include <stdlib.h>

#include "execShell.h"

int main(int argc, char **argv){
    char buf[256] = {'\0'};
    currentPromtPrint();
    while(true){
        fgets(buf, sizeof(buf), stdin);
        if(isChangeDir(buf) == true)
            changeDir(buf);
        else if(strcmp(buf, "exit\n") == 0)
                return 0;
        else
            shell(buf);
        currentPromtPrint();
    }
    return 0;
}
