#ifndef __EXECSHELL_H__
#define __EXECSHELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define LEN_DIR 256
#define PATH_SHELL "C:\\Windows\\System32\\cmd.exe"
INT shell(CHAR **args);

CHAR **parserCommand(CHAR *cmd);

BOOL changeDirs(CONST CHAR *path);

#endif // __EXECSHELL_H__
