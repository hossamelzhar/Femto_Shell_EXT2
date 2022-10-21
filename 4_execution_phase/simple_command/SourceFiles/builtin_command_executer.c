#include "../HeaderFiles/builtin_command_executer.h"


int builtin_command_executer(char** command_args, linked_list_T **MyLocals)
{
	int  RetStat = 0;
	int  detect  = 0;
	int  index   = 0;
	char *cwd = getcwd(NULL, 0);
	char *last_cwd = getenv("last_cwd");

	/*********************************************************************************************************************/	

	if( (memcmp(command_args[0], "set", 3) == 0) )
		{
			detect = 1;
			display_locals(*MyLocals);
		}
		else if( (memcmp(command_args[0], "unset", 5) == 0) )
		{
			detect = 1;
			remove_local_var(MyLocals, command_args[1]);
			
		}
		else if( memcmp(command_args[0], "export", 6) == 0 )
		{
			detect = 1;
			export_var(*MyLocals, command_args);
		}
		else if( memcmp(command_args[0], "cd", 2) == 0 )
		{
			detect = 1;
			if( memcmp(command_args[1], "-", 1) == 0 )
			{
				if(last_cwd != NULL)
		   		{	
		   			last_cwd = getenv("last_cwd");
					RetStat = chdir(last_cwd);
					if(RetStat == 0)
					{
						last_cwd = cwd;
						setenv("last_cwd", last_cwd, 1);
					}
					else
					{
						printf("Invalid Directory\n");
					}
		   		}
				else 
				{
					printf("cd: OLDPWD not set\n");
				}
			}
			else
			{
				//save the last dir
				last_cwd = cwd;
				printf("last : %s -- cwd : %s\n", last_cwd, cwd);
				setenv("last_cwd", last_cwd, 1);
				RetStat = chdir(command_args[1]);
				if(RetStat == -1)
				{
					printf("Invalid Directory\n");
				}
				else{}
			}
		}
		else if( memcmp(command_args[0], "help", 4) == 0 )
		{
			command_args = (char**) realloc(command_args, 3 * sizeof(char*));
			command_args[0] = (char*) realloc(command_args[0], 5 * sizeof(char));
			command_args[1] = (char*) realloc(command_args[1], 9 * sizeof(char));
			strcpy(command_args[0], "less");
			strcpy(command_args[1], "help.txt");
			command_args[2] = NULL;
			detect = 0;//Go To External Execution 
		}
		else if( memcmp(command_args[0], "exit", 4) == 0 )
		{
			detect = 1;
			printf("GoodBye :)\n");
			//Before Exit Don't Forget To Free All Allocated Memory
			
			while(NULL != command_args[index])
			{
				free(command_args[index]);
				index++;
			}
			free(command_args);
			free(cwd);
			exit(1);
		}
		else
		{
			detect = 0;
		}
		
		if(detect == 1)
		{
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
			free(cwd);
			cwd = NULL;
			/**************************************/
		}
		else{}

	
	return detect;
}
