#include "../HeaderFiles/export_var.h"


void export_var(linked_list_T *MyLocals, char **names)
{
        if(MyLocals != NULL)
        {

			int index = 1;//skip names[0] that eqaul "export" command
			while(names[index] != NULL)
			{
				linked_list_T *temp = MyLocals;
            	int RetVal = 2; //any value other than 0 , -1
            	while(temp != NULL)
	            {

    	                if( strcmp(names[index], temp->var_name) == 0 )
            	        {
                    	        RetVal = setenv(temp->var_name, temp->var_data, 1);
                            	if(RetVal == -1)
	                            {
    	                                printf("Failed To Add The Variable InTo Environment Variables\n");
            	                }
                    	        else if(RetVal == 0)
                            	{
                                    	break;

	                            }else{}
    	                }
            	        else
                    	{

                            	temp = temp->next;
	                            if(temp == NULL)
                            	{
                                    	//this means we reached the last node and name not found in the list
	                                    printf("%s Not Exisist\n", names[index]);

    	                        }else{}
            	        }
           		 }
				
				index++;
			}
	    }
        else
        {
                printf("My List Is Empty\n");
        }

}

