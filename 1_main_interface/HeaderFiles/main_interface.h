#ifndef _MAIN_INTERFACE_H_
#define _MAIN_INTERFACE_H_

#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#include "../../2_reading_phase/HeaderFiles/begining_ending_spaces_remover.h"
#include "../../2_reading_phase/HeaderFiles/line_commands_parser.h"
#include "../../2_reading_phase/HeaderFiles/preprocessor.h"

#include "../../3_local_variables/HeaderFiles/search_var_name.h"
#include "../../3_local_variables/HeaderFiles/local_var_parser.h"
#include "../../3_local_variables/HeaderFiles/add_local_var.h"
#include "../../3_local_variables/HeaderFiles/display_locals.h"
#include "../../3_local_variables/HeaderFiles/export_var.h"
#include "../../3_local_variables/HeaderFiles/linked_list_type.h"

#include "../../4_execution_phase/pipeline/HeaderFiles/pipeline_commands_geter.h"
#include "../../4_execution_phase/pipeline/HeaderFiles/pipeline_executer.h"
#include "../../4_execution_phase/redirection/HeaderFiles/get_command_and_files.h"
#include "../../4_execution_phase/redirection/HeaderFiles/input_output_error_redirection_executer.h"
#include "../../4_execution_phase/redirection/HeaderFiles/Redirect_input_output_error.h"
#include "../../4_execution_phase/simple_command/HeaderFiles/simple_command_parser.h"
#include "../../4_execution_phase/simple_command/HeaderFiles/simple_command_executer.h"


#endif
