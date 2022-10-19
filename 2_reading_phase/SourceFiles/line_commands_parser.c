#include "../HeaderFiles/line_commands_parser.h"

/*****
 * from the first char in line, after removing begining spaces
 * start copy in temp array util you found semicolon in the next iterat
 * put NULL termination in temp array to complete the current command
 * copy it in commands array
 * increment command counter to be ready to alloc a new memory space to another command if exisist
 * after parsing the line put NULL as end of commands
 * Return commands terminated by NULL OR Return the same line if no semicolons founded
 * */
char** line_commands_parser(char line[])
{

	char   command_counter = 0;
    char   iterator        = 0;
    char   temp_index      = 0;
    char   temp_arr[100];

	char** commands        = (char**) calloc(1, sizeof(char*));
	commands[0] = NULL;
	
	/**********************************************************************************************************************************************/
	
	while(line[iterator] != '\0')
	{
		if( (line[iterator] == ';') || (line[iterator+1] == '\0') )//if the next char is semicolon, then the current command finished
        {
        	if( (line[iterator+1] == '\0') && (line[iterator] != ';') && (line[iterator] != ' ') )
        	{
        		temp_arr[temp_index] = line[iterator];//copy from line to my temp array
            	temp_index++;
        	}
        	else{}
        	
        	commands = (char**) realloc(commands, (command_counter + 2) * sizeof(char*));
        	if(NULL != commands)
        	{
		        temp_arr[temp_index] = '\0';//put NULL termination to end it
		        commands[command_counter] = (char*)calloc(strlen(temp_arr), sizeof(char));//create a memory space in heap to hold this command
		        if(NULL != commands[command_counter])
		        {
					strcpy(commands[command_counter], temp_arr);//copy the temp array to the real command memory space
		            command_counter++;//increment command counter to be ready if there is another command in line
		            commands[command_counter] = NULL;//termination to commands
		            memset(temp_arr, 0, strlen(temp_arr));//clear temp arr
		            temp_index = 0; //clear temp array index
		        }
		        else
		        {
		            /*Return NULL*/
				}
				
				iterator += 1; //move to next char after semicolon
		        while( (line[iterator] == ';') || (line[iterator] == ' ') ) //still here until semicolons and spaces finished
		        {
		                iterator++;
		        }
			}
			else{}
		}
		else
		{
			if(line[iterator] == ' ') //let one space only between args
			{
				temp_arr[temp_index] = line[iterator];//copy from line to my temp array
		        temp_index++;
				iterator++;
				while(line[iterator] == ' ')
				{
					iterator++;
				}
			}
			else
			{
				temp_arr[temp_index] = line[iterator];//copy from line to my temp array
		        temp_index++;
				iterator++;
			}
		}

	}

	return commands;
}
