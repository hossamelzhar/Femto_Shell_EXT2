#ifndef PIPLINE_EXEC_H_
#define PIPLINE_EXEC_H_

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


#include "pipeline_commands_geter.h"
#include "../../redirection/HeaderFiles/get_command_and_files.h"
#include "../../redirection/HeaderFiles/input_output_error_redirection_executer.h"
#include "../../simple_command/HeaderFiles/simple_command_parser.h"

extern char **environ;

void pipeline_executer(char command[]);

#endif
