#include "../HeaderFiles/pipeline_commands_geter.h"

#include <stdio.h>

char** pipeline_commands_geter(char command[])
{
	int  iterator   = 0;
	char temp_arr[100];
	int  temp_index = 0;
	char out_temp_file[] = ">TM.txt";
	char  in_temp_file[] = "<TM.txt";

	char** commands = (char**) calloc(1, sizeof(char*));
	int    command_index = 0;
	int    detect   = 0;
	
	/*********************************************************************************************************************************/
	
	if(NULL != commands)
	{
		/*******************get first command in line before '|' char********************************/
		while(command[iterator] != '|')
		{

			temp_arr[temp_index] = command[iterator];
			temp_index++;

			iterator++;
			
		}//while loop
		temp_arr[temp_index] = '\0';
		/********************************************************************************************/
		
		/***********************put output file after the command befor '|' char*********************/
		strcat(temp_arr, out_temp_file);
		commands = (char**) realloc(commands, (command_index + 2) * sizeof(char*));		
		commands[command_index] = (char*) calloc(strlen(temp_arr), sizeof(char));
		if(NULL != commands[command_index])
		{
			strcpy(commands[command_index], temp_arr);
			command_index++;
			commands[command_index] = NULL;//as it may be its the last arg
			memset(temp_arr, 0, strlen(temp_arr));
			temp_index = 0;

		}
		else{}
		/***********************************************************************************************/
		
		
		iterator++; //move it to the next char
		
		/***************************check if the next char is '|' OR ' '***************************************/
		if(command[iterator] == '|') //then '|' next to '|', and its wrong
		{
			free(commands[command_index-1]);
			commands[command_index-1] = NULL;
			free(commands);
			commands = NULL;
			
			return commands;
		}
		else{}
		if(command[iterator] == ' ')
		{
			iterator++;
		}
		else{}
		/***********************************************************************************************/
		
		/********************start put input file after the command after '|' char**********************/
		detect = 1;
		while(command[iterator] != '\0')
		{
			if( ( ( (command[iterator] == ' ') || (command[iterator+1] == '\0') ) && (command[iterator] != '|') ) && (detect == 1) )
			{
				if(command[iterator+1] == '\0')
				{
					temp_arr[temp_index] = command[iterator];
					temp_index++;
				}
				temp_arr[temp_index] = '\0';
				strcat(temp_arr, in_temp_file);
				temp_index += strlen(in_temp_file);
				detect = 0;
				iterator++;
			}
			else
			{
				if(command[iterator] == '|') //then '|' next to '|', and its wrong
				{
					/*Nothing*/
				}
				else
				{
					temp_arr[temp_index] = command[iterator];
					temp_index++;
					iterator++;
				}
			}
			
			if( ( (command[iterator] == '|') || (command[iterator+1] == '\0') ) && (detect == 0) )  
			{
				
				temp_arr[temp_index] = '\0';
				commands = (char**) realloc(commands, (command_index + 2) * sizeof(char*));		
				commands[command_index] = (char*) calloc(strlen(temp_arr), sizeof(char));
				if(NULL != commands[command_index])
				{
					strcpy(commands[command_index], temp_arr);
					command_index++;
					commands[command_index] = NULL;//as it may be its the last arg
					memset(temp_arr, 0, strlen(temp_arr));
					temp_index = 0;
					detect = 1;
					
					iterator++;//next to '|' char
					
					if(command[iterator] == ' ')
					{
						iterator++;
					}
					else{}

				}
				else{}
			}
			else{}
			
			
			
		}
		/**************************************************************************************************/
		

	}
	else{}


	return commands;
}
