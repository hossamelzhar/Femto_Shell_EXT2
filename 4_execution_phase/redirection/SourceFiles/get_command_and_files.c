#include "../HeaderFiles/get_command_and_files.h"

#include <stdio.h>

char** get_command_and_files(char command[], char*** files)
{
	int  iterator     = 0;
	char temp_arr[200];
	int  temp_index   = 0;
	int  args_counter = 0;
	int  files_counter= 0;
	
	/*********************************************************************************************************************/
	
	char** command_args = (char**) calloc(1, sizeof(char*));
	command_args[0] = NULL;
	(*files) = (char**) calloc(1, sizeof(char*));
	(*files)[0] = NULL;
	
	if(NULL == command_args)
	{
		return command_args;//failed from the begining ya 3m
	}
	else
	{
		/********************************Get command and its args********************************************/
		while( (command[iterator] != '>') &&  (command[iterator] != '<') )
		{
			if( (command[iterator] == ' ') || (command[iterator+1] == '>') || (command[iterator+1] == '<') 
				                         || ( (command[iterator+1] == '2')&&(command[iterator+2] == '>') ) )
			{
				if( ((command[iterator+1] == '>') || (command[iterator+1] == '<') 
				 || ( (command[iterator+1] == '2')&&(command[iterator+2] == '>') )) &&  (command[iterator] != ' ') )//cut here
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
			
			iterator++ ;;
			
		}//command while loop
		/******************************************************************************************************/

		/***************************************Get files names************************************************/
		if(NULL != (*files))
		{
			iterator++; //move iterator to next char after redirection chars
			if(command[iterator] == '>') //then the ender of previous loop was "2>", then increament iterator
			{
				iterator++;
			}
			else{}
			
			if(command[iterator] == ' ')//remove space after redirection chars
			{
				iterator++;
				
			}else{}

			while(command[iterator] != '\0')
			{
				if( (command[iterator] == '>') || (command[iterator] == '<') 
 	           || ( (command[iterator] == '2')&&(command[iterator+1] == '>') ) || (command[iterator+1] == '\0') )
				{
					if(command[iterator+1] == '\0')
					{
						temp_arr[temp_index] = command[iterator];
            	 		temp_index++;
					}
					else{}
					
					(*files) = (char**) realloc((*files), (files_counter + 2) * sizeof(char*));
					temp_arr[temp_index] = '\0';
					(*files)[files_counter] = (char*) calloc(strlen(temp_arr), sizeof(char));
					if(NULL != (*files)[files_counter])
					{
						strcpy((*files)[files_counter], temp_arr);
                        files_counter++;
                        (*files)[files_counter] = NULL;//as it may be its the last file
                        memset(temp_arr, 0, strlen(temp_arr));
    	                temp_index = 0;
						
						//go to next file
						iterator++;
		   		    	
						if ( (command[iterator] == '>') || (command[iterator] == '<') )//then i was interrupted by ' ' char
                        {
							iterator++;
					    }
						else if( (command[iterator] == '2')&&(command[iterator+1] == '>') )
						{
							iterator += 2;
						}
						else{}

					}
					else{}
				}
				else
       		    {
       		    	if(command[iterator] == ' ')
       		    	{
       		    		iterator++;
       		    	}
       		    	else
       		    	{
       		    		temp_arr[temp_index] = command[iterator];
		        	 	temp_index++;
		            	iterator++;
       		    	}
       		    	
					
      	        }

			}//files while loop

			
		}
		else{}
		/*****************************************************************************************************************/

	}

	return command_args;
}
