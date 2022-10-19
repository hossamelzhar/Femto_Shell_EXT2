#include "../HeaderFiles/add_local_var.h"


void add_local_var(linked_list_T **MyLocals, char *name, char *data)
{


		int index  = 1;
		int detect = 0;//detect = 0, its a legal name;  detect = 1, illegal name
		char *env_var = NULL;
		linked_list_T  *new_node = NULL;
		linked_list_T  *temp = *MyLocals;
		
		/******** Firstly check if the var name is legal ********************/
		if( ( (name[0] >= 'A')&&(name[0] <= 'Z') ) 
		  ||( (name[0] >= 'a')&&(name[0] <= 'z') )
		  ||( (name[0] == '_') ) )
		{
			while(name[index] != '\0')
			{
				if( ( (name[index] >= 'A')&&(name[index] <= 'Z') )
		      	  ||( (name[index] >= 'a')&&(name[index] <= 'z') )
				  ||( (name[index] >= '0')&&(name[index] <= '9') )
		      	  ||( (name[index] == '_') ) )
				{
					/*nice and continue*/
				}
				else//illegal name
				{
					detect = 1;
					break;
				}
				
				index++;
			}
		}
		else//illegal name
		{
			detect = 1;
		}
		/********************************************************************/

		
		if(detect == 0)
		{
				/**** check if the var name is environ ****/
				env_var = getenv(name);
				if(NULL != env_var)
				{
						setenv(name, data, 1);
				}
				else{}
				/******************************************/
				
				/********************* add in my locals ****************************/
				//add var in first node in case the list is empty
				if(NULL == *MyLocals) 
				{
				    	new_node = (linked_list_T*)calloc(1, sizeof(linked_list_T));
					    if(NULL == new_node)
					    {
				            	printf("Failed To Add Variable %s\n", name);
				    	}
					    else
					    {
				    	        *MyLocals = new_node;
					    }
				}
				else 
				{
						//search if this var is already in my list, then update it , else add it to my list
				    	new_node = search_var_name(*MyLocals, name);
					    if(new_node == NULL)
					    {
			    	        //then this variable not exisists
				            //create new node to store the new variable
				            new_node = (linked_list_T*)calloc(1, sizeof(linked_list_T));
			            	if(NULL == new_node)
			    	        {
				                    printf("Failed To Add Variable %s\n", name);
				            }
			            	else
			    	        {
			    	        		//reach the last node
				                    while(temp->next != NULL) 
				                    {
			                            	temp = temp->next;
			                    	}
			            	        //after holding the last node, its time to link the new node to last node
			    	                temp->next = new_node;
				            }
					    }
				    	else
				    	{
				    		free(new_node->var_name);
				    		new_node->var_name = NULL;
				    		free(new_node->var_data);
				    		new_node->var_data = NULL;
				    		new_node->var_name = name;
						   	new_node->var_data = data;
						   	return;
				    	}

				}

				////At this point, new_node have address of a new variable OR an exisisting variable

				//new_node->var_name = (char*) calloc(strlen(name), sizeof(char));
				//new_node->var_data = (char*) calloc(strlen(data), sizeof(char));
				//add data to the new node
				new_node->var_name = name;
			   	new_node->var_data = data;

				//the new node is the last node so
				new_node->next = NULL;
				
				//free allocated memory for prameters name and data
				//free(name);
				//free(data); 

		
		}
		else //illegal name
		{
				printf("%s=%s : command not found\n",name ,data);
		}
	


}
