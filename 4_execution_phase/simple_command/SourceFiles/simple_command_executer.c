#include "../HeaderFiles/simple_command_executer.h"


void simple_command_executer(char command[], linked_list_T **MyLocals)
{
	
	
	int detect = 0;
	int arg_index = 0;
	char** command_args = NULL;
	

	command_args = simple_command_parser(command);

	if(NULL != command_args)
	{
	
		detect = builtin_command_executer(command_args, MyLocals);
		if(detect == 0)
		{
			external_command_executer(command_args);
		}
		else{}
		
	}
	else
	{
		printf("Failed To get command arguments\n");
	}

	
}
