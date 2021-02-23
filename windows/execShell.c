#include "execShell.h"

bool isChangeDir(const char *cmd){
    if(cmd[0] == 'c' && cmd[1] == 'd' && cmd[2] == ' ')
        return true;
    return false;
}

void currentPromtPrint(void){
    char buf[LEN_PROMT];
    ZeroMemory(buf, LEN_PROMT);
    GetCurrentDirectory(LEN_PROMT, buf);
    if(buf[strlen(buf) - 1] == '\\')
        printf("\n%s>", buf);
    else
        printf("\n%s>", buf);
}

bool changeDir(char *path){
    char *currDir = NULL;
    DWORD len = 0;
    strtok(path, " ");
    currDir = strtok(NULL, " ");
    if(currDir == NULL){
       len = GetCurrentDirectory(LEN_BUF, currDir);
       currDir[len] = '\0';
       return SetCurrentDirectory(currDir);
    }
    return SetCurrentDirectory(currDir);
}

void shell(char *cmd){
    FILE *file = NULL;
    char buf[LEN_BUF] = {'\0'};
    if((file = _popen(cmd, "r")) != NULL){
        while(fgets(buf, sizeof(buf), file) != NULL){
            printf("%s", buf);
        }
        fclose(file);
    }
}
