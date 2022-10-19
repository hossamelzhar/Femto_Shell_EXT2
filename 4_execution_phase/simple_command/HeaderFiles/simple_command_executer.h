#ifndef EXEC_SIMP_COMM_H
#define EXEC_SIMP_COMM_H



#include "simple_command_parser.h"
#include "builtin_command_executer.h"
#include "external_command_executer.h"



void simple_command_executer(char command[], linked_list_T **MyLocals);

#endif
