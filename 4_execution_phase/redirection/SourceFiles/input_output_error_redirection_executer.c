#include "../HeaderFiles/input_output_error_redirection_executer.h"


void input_output_error_redirection_executer(char command[], char** command_args, char** files)
{

	int  index   = 0;
	
	if( (NULL != command_args) || (NULL != files) )
	{
		//fork parent process to create new process (child)
		RetStat = fork();

		if(RetStat > 0)
		{
			//this is parent
		    wait(&RetStat);
		    
		    /******* free allocated memory ********/
		    while(command_args[index] != NULL)
		    {
		    	free(command_args[index]);
		    	command_args[index] = NULL;
		    	index++;
		    }
		    free(command_args);
		    command_args = NULL;
		    index=0;
		    while(files[index] != NULL)
		    {
		    	free(files[index]);
		    	files[index] = NULL;
		    	index++;
		    }
		    free(files);
		    files = NULL;
		    /**************************************/
		}
		else if(RetStat == 0)
		{
		
			//this is the child process
			
			Redirect_input_output_error(command, files);
		    	
			//after all redirections, Now its time to execute this command and create its process
		    execvp(command_args[0], command_args);
		    printf("Failed To Execute %s\n", command_args[0]);
			exit(1);
	 	}

	}
	else
	{
		printf("empty arguments\n");
	} 	
 	



}


