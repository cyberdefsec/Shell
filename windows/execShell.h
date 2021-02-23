#ifndef __EXECSHELL_H__
#define __EXECSHELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

#define LEN_BUF 1024
#define LEN_PROMT 512

void shell(char *cmd);

bool isChangeDir(const char *cmd);

bool changeDir(char *path);

void currentPromtPrint(void);

#endif // __EXECSHELL_H__
