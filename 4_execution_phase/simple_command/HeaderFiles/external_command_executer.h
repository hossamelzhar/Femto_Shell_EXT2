#ifndef EXT_COMMAND_H
#define EXT_COMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;
extern int  RetStat;

void external_command_executer(char** command_args);

#endif
