#include "../HeaderFiles/pipeline_executer.h"


void pipeline_executer(char command[])
{
    int  pipe_fd         = 0;
    int  command_index   = 0;
    int  args_index      = 0;
    int  files_index     = 0;

    char **command_args = NULL;
    char **files        = NULL;
    
    /**************************************************************************************************************************/

    char **commands = pipeline_commands_geter(command);
    if (commands == NULL) 
    {
		printf("Error Command\n");
    }
    else
    {
	    
		while (commands[command_index] != NULL) 
		{
			command_args = get_command_and_files(commands[command_index], &files);
			if( (NULL != command_args) && (NULL != files) )
			{
				input_output_error_redirection_executer(commands[command_index], command_args, files);
				//free command_args and files in this executer function, Done
			}
			else
			{
				printf("failed to get command arguments to redirect it\n");
			}
			command_index++;
			
		}//while loop
		
	}

		/************ free all memory ********************/
			command_index = 0;
			while (commands[command_index] != NULL)
			{
				free(commands[command_index]);
				commands[command_index] = NULL;
				command_index++;
			}
			free(commands);
			commands = NULL;
		/*************************************************/
		
		//remove the temp file for pipelining
		unlink("TM.txt");
		
		
		
}
		
		
		
