#ifndef PREPROCESS_H
#define PREPROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../../3_local_variables/HeaderFiles/search_var_name.h"

extern int  RetStat;

char* preprocessor_phase(char *command, linked_list_T *MyLocals, int* equal_char, int* pipeline, int* change_ioe);


#endif
