#include "../HeaderFiles/remove_local_var.h"


void remove_local_var(linked_list_T **MyLocals, char *name)
{
	linked_list_T *removed_node = NULL;
	linked_list_T *prev_node = *MyLocals;
	
	if(NULL != *MyLocals)
	{
			removed_node = search_var_name(*MyLocals, name);
			if(NULL != removed_node)
			{
				//check if the required node is the first node
				if(removed_node == (*MyLocals))
				{
					printf("removed_node %p - *MyLocals %p\n",removed_node , *MyLocals);
					(*MyLocals) = removed_node->next;
					printf("(*MyLocals)->data = %s\n", (*MyLocals)->var_data);
					printf("removed_node->next->data = %s\n", (removed_node->next)->var_data);
					free(removed_node);
					removed_node = NULL;
					printf("removed_node %p - *MyLocals %p\n",removed_node , *MyLocals);
				}
				else
				{	
					//Get The Previous Node of the node that will be removed to link it to the next node of it
					while(prev_node->next != removed_node)
					{
						prev_node = prev_node->next;
					}
					//after loop finished, removed node holds the address of the node will be removed
					//and prev_node now holds the address of the previous node
					
					//link prev to next of removed
					prev_node->next = removed_node->next;
					//then free removed node to delete it
					free(removed_node);
					removed_node = NULL;
					//DONE
				}	
		}
		else
		{
			printf("%s NOT EXISISTS\n", name);
		}
	}
	else
	{
		 printf("My List Is Empty\n");
	}
}

