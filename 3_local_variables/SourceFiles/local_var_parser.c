#include "../HeaderFiles/local_var_parser.h"

#include <stdio.h>

char* local_var_parser(char* command, char***args)
{
	(*args) = (char**) calloc(2, sizeof(char*));
	int  iterator   = 0;
	int  temp_index = 0;
	char temp_arr[200];

	/****************************************get variable name**************************************************************************/
	while(command[iterator] != '=') //after this loop finished, iterator will have index of '='; //ISA 
	{
		if( (command[iterator] == ' ') || (command[iterator] == '>') || (command[iterator] == '<') 
		                               || ( (command[iterator] == '2')&&(command[iterator+1] == '>') ) )//its not a local variable adding
		{	
			(*args)[0] = NULL;
			(*args)[1] = NULL;
			return command;
		}
		else
		{
			temp_arr[iterator] = command[iterator];
		}

		iterator++;

	}
	temp_arr[iterator] = '\0';

	//allocate a memory for the first element in args with length of variable name
	(*args)[0] = (char*) calloc(strlen(temp_arr), sizeof(char));
	if(NULL != (*args)[0])
	{
		//copy variable name in first element in args
		strcpy((*args)[0], temp_arr);
	}
	else
	{
		/*return VAR_NAME by NULL, this will be handled in the upper layer*/
	}
	/***************************************************************************************************************************************/
	
	/***********************************************get variable data***********************************************************************/
	//MOVE iterator to the next char after '='
	iterator = iterator + 1;
	memset(temp_arr, 0, strlen(temp_arr));
	temp_index = 0;
	while( (command[iterator] != ' ') &&  (command[iterator] != '\0') )
    {
        temp_arr[temp_index] = command[iterator];
        temp_index++;
        iterator++;
        if(command[iterator] == '\0')
        {
        	temp_arr[temp_index] = command[iterator];
	        temp_index++;
        }
        else{}
		
    }

    temp_arr[temp_index] = '\0';


	//allocate a memory for the second element in args with length of variable data
    (*args)[1] = (char*) calloc(strlen(temp_arr), sizeof(char));
	if(NULL != (*args)[1])
    {
        //copy variable data in second element in args
    	strcpy((*args)[1], temp_arr);
	}
    else
    {
    	/*return VAR_DATA by NULL, this will be handled in the upper layer*/
    }
    /*******************************************************************************************************************************************/

    
	//check if the command not finished
	if(command[iterator] != '\0')
	{
		while(command[iterator] == ' ')
		{
			iterator++;
		}

		memset(temp_arr, 0, strlen(temp_arr));
		temp_index = 0;
		while(command[iterator] != '\0')
		{
			temp_arr[temp_index] = command[iterator];
			temp_index++;
			iterator++;
		}
		temp_arr[temp_index] = '\0';
		memset(command, 0, strlen(command));
		memcpy(command, temp_arr, strlen(temp_arr)); //return the remaining command part
	}
	else
	{
		free(command); 
		command = NULL;
	}
	
	
	return command;
}
