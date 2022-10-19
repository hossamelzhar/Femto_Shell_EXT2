#include "../HeaderFiles/simple_command_parser.h"



char** simple_command_parser(char command[])
{
	int  iterator     = 0;
	char temp_arr[200];
	int  temp_index   = 0;
	int  args_counter = 0;
	
	/*********************************************************************************************************************/
	
    char** command_args = (char**) calloc(1, sizeof(char*));
	command_args[0] = NULL;
    
    if(NULL!= command_args)
    {
		//start parsing ^_^
		while(command[iterator] != '\0')
		{
		    if( (command[iterator] == ' ') || (command[iterator + 1] == '\0') )
		    {
		    	if(command[iterator + 1] == '\0')
		    	{
		    		temp_arr[temp_index] = command[iterator];
		    		temp_index++;
		    	}
		    	else{}
		    	
				command_args = (char**) realloc(command_args, (args_counter + 2) * sizeof(char*));
				temp_arr[temp_index] = '\0';
				command_args[args_counter] = (char*) calloc(strlen(temp_arr), sizeof(char));
				if(NULL != command_args[args_counter])
				{
					strcpy(command_args[args_counter], temp_arr);
					args_counter++;
					command_args[args_counter] = NULL;//as it may be its the last arg
					memset(temp_arr, 0, strlen(temp_arr));
					temp_index = 0;

				}
				else{}
		        
		    }
		    else
		    {
		    	temp_arr[temp_index] = command[iterator];
		    	temp_index++;	
		    }
		    
		    iterator++;
		    
		}
		
	}
	else{}

	return command_args;
}
