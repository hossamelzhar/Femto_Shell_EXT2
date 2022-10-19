#include "../HeaderFiles/search_var_name.h"


linked_list_T *search_var_name(linked_list_T *MyLocals, char *name)
{
        linked_list_T *temp = MyLocals;
        
        if(NULL == MyLocals)
        {
        	return MyLocals;
        }
		else
		{
		    while(temp != NULL)
		    {
		            if( memcmp(name, temp->var_name, strlen(name)) == 0 )
		            {
		                    break; //if founded, return its address
		            }
		            else
		            {
		                    temp = temp->next;// else continue, and if not founded, temp will = NULL
		            }
		    }
		}

        return temp;
}

