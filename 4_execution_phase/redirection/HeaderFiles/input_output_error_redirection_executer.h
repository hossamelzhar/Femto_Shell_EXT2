#ifndef _SPECIAL_CHARS_H_
#define _SPECIAL_CHARS_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#include "Redirect_input_output_error.h"

extern char **environ;
extern int  RetStat;

void input_output_error_redirection_executer(char command[], char** command_args, char** files);

#endif
