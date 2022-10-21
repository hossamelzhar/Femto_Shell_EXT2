#include "../HeaderFiles/preprocessor.h"



char* preprocessor_phase(char *command, linked_list_T *MyLocals, int* equal_char, int* pipeline, int* change_ioe)
{
	
	
	int  index      = 0;
	int  part_index = 0;
	int  temp_index = 0;
	int  detect     = 0;
	
	char temp_arr[200];
	char preprocessed_command[200];
	char *processed_command = NULL;
	
	char *env_var = NULL;
	linked_list_T * node_address = NULL;
	

	/************************************************************************************************************************/
	
	while(command[index] != '\0')
	{
		if(command[index] == '$')
		{
			//move index to next char to "remove '$' char from my new command"
			index++;
			if(command[index] == '?')
			{
				temp_arr[0] = WEXITSTATUS(RetStat) + '0';
				temp_arr[1] = '\0';
				strcat(preprocessed_command, temp_arr);
				part_index += strlen(temp_arr);
				index++;
			}
			else
			{
				//get var name
				while( (command[index] != ' ') && (command[index] != '\0') )
				{
					temp_arr[temp_index] = command[index];
					temp_index++;
					index++;
					
				}
				
				temp_arr[temp_index] = '\0';				
			
				temp_index = 0;
				//search for this name in my locals list
				node_address = search_var_name(MyLocals, temp_arr);
				if(NULL != node_address)//var name founded
				{
					strcpy(temp_arr, node_address->var_data);
					strcat(preprocessed_command, temp_arr);
					part_index += strlen(temp_arr);
					detect = 1;
				}
				else{}
				//check if it is in environment variables
				env_var = getenv(temp_arr);
				if(NULL != env_var)
				{
					strcat(preprocessed_command, env_var);
					part_index += strlen(env_var);
				}
				else
				{
					if(detect == 0)
					{
						preprocessed_command[part_index] = ' ';
						part_index++;
					}
					else{}
				}
			}
			
		}
		else
		{
			/**copy the each main command char to an array until you found '$' char**/
			preprocessed_command[part_index] = command[index];
			part_index++;
			preprocessed_command[part_index] = '\0';
			index++;
		}
		
		/************while preprocessing each command, check if there is special characters*********************/
		//may be we will need to add a local variable
		if(command[index] == '=')
		{
			*equal_char = 1;
		}
		//we have a pipeline in our command
		else if(command[index] == '|')
		{
			*pipeline = 1;
		}
		//we will redirect input or output or error or all of them
		else if( (command[index] == '>') || (command[index] == '<') )//input output redirection
		{
			*change_ioe = 1;
		}
		else{}
		/*******************************************************************************************************/
		
		
	} 

	//return the preprocessed command in its memory
	processed_command = (char*) calloc(strlen(preprocessed_command), sizeof(char));
	if(NULL != processed_command)
	{
		memcpy(processed_command, preprocessed_command, strlen(preprocessed_command));
	}
	else
	{
		printf("NULL\n");
	}
	return processed_command;
}
