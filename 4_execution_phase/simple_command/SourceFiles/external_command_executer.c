#include "../HeaderFiles/external_command_executer.h"


void external_command_executer(char** command_args)
{
	int  index   = 0;
	
	/***************************************************************/
	
	RetStat = fork();
	if(RetStat > 0)
	{
		//this is parent
		wait(&RetStat);
		/********free allocated memory*********/		
		index = 0;
		while(NULL != command_args[index])
		{
			free(command_args[index]);
			command_args[index] = NULL;
			index++;
		}
		free(command_args);
		command_args = NULL;
		/**************************************/
	}
	else if(RetStat == 0)
	{
		//this is child
		execvp(command_args[0], command_args);
		printf("Failed To Execute %s\n", command_args[0]);
		exit(1);
	}
	/***************************************************************/	

}
