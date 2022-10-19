#ifndef BUILTIN_H
#define BUILTIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../../../3_local_variables/HeaderFiles/export_var.h"
#include "../../../3_local_variables/HeaderFiles/display_locals.h"
#include "../../../3_local_variables/HeaderFiles/remove_local_var.h"

int builtin_command_executer(char** command_args, linked_list_T **MyLocals);

#endif
