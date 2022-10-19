#include "../HeaderFiles/display_locals.h"

void display_locals(linked_list_T *MyLocals)
{
        if(MyLocals != NULL)
        {
                linked_list_T *temp = MyLocals;
                int index = 0;

                while(temp != NULL)
                {
                        printf("LOCAL_ARG[%i] : %s = %s\n",index, temp->var_name, temp->var_data);
                        index++;
                        temp = temp->next;
                }
        }
        else
        {
                printf("My List Is Empty\n");
        }
}
