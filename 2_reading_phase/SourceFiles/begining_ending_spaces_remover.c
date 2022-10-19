#include "../HeaderFiles/begining_ending_spaces_remover.h"

void begining_ending_spaces_remover(char line[])
{
	char  temp_arr[100];
	int   temp_index = 0;
	int   iterator   = 0;
	
	/******************Remove the begining spaces******************/
		while(line[iterator] == ' ')
		{
			iterator++;
		}

		if(iterator != 0)//if there is spaces in the begining
		{
			while(line[iterator] != '\0')
			{
				temp_arr[temp_index] = line[iterator];
				temp_index++;
				iterator++;
			}
			temp_arr[temp_index] = '\0';
			
			strcpy(line, temp_arr);
		}
		else{}//no spaces founded in the begining
	/***************************************************************/
	
	
	/****************Remove the Ending spaces***********************/ 
		iterator = strlen(line) - 1;
		while(line[iterator] == ' ')
		{
			iterator--;
		}
		
		for(temp_index = 0; temp_index <= iterator; temp_index++)
		{
			temp_arr[temp_index] = line[temp_index];
		}
		temp_arr[temp_index] = '\0';
		strcpy(line, temp_arr);
	/****************************************************************/
	

}
