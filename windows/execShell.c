#include "execShell.h"

static CHAR *remove_crlf(CHAR *str){
    INT len = strlen(str) - 1;
    CHAR *t = str;
    if(*t == '\r' || *t == '\n')
        return NULL;
    while((t[len] == '\n' || t[len] == '\r') && len > 0)
        len--;
    t[len + 1] = '\0';
    return str;

}


BOOL changeDirs(CONST CHAR *path){
    CHAR currDir[LEN_DIR] = {'\0'};
    DWORD len = 0;
    if(path == NULL){
       len = GetCurrentDirectory(LEN_DIR, currDir);
       currDir[len] = '\0';
       return SetCurrentDirectory(currDir);
    }
    return SetCurrentDirectory(path);
}

INT shell(CHAR **args){
    PROCESS_INFORMATION pinfo;
    STARTUPINFO sinfo;
    HANDLE pipeRead, pipeWrite;
    ZeroMemory(&pinfo, sizeof(pinfo));
    ZeroMemory(&sinfo, sizeof(sinfo));
    if(CreatePipe(&pipeRead, &pipeWrite, NULL, 0)){
        sinfo.cb = sizeof(STARTUPINFO);
        sinfo.hStdInput = pipeRead;
        sinfo.hStdOutput = pipeWrite;
        sinfo.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
        if(CreateProcess(PATH_SHELL, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &sinfo, &pinfo)){
            return 0;
        }
    }
    return 0;
}

CHAR **parserCommand(CHAR *cmd){
    CHAR **args = NULL;
    int row = 0;
    if(remove_crlf(cmd) == NULL)
        return NULL;
    if((args = (CHAR**)malloc((row + 1) * sizeof(CHAR*))) != NULL){
        args[row] = strtok(cmd, " ");
        while(args[row++] != NULL){
            args = (CHAR**)realloc(args, (row + 1) * sizeof(CHAR*));
            args[row] = strtok(NULL, " ");
        }
        return args;
    }
    return NULL;
}
