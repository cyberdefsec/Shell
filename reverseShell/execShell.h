#ifndef __EXECSHELL_H__
#define __EXECSHELL_H__

int shell(char **args);

char **parse_command(char *cmd);

int changed_dirs(const char *path);

#endif
