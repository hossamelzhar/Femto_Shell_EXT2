#include "../HeaderFiles/Redirect_input_output_error.h"



void Redirect_input_output_error(char command[], char** files)
{
	int  iterator    = 0;
    int  files_index = 0;
    int  input_fd    = 0;
    int  output_fd   = 0;
    int  error_fd    = 0;

	//redirection configurations
    while( (command[iterator] != '\0') && (files[files_index] != NULL) )
    {
		//input redirection
        if(command[iterator] == '<')
        {
    		//open the file you want to be the new input source
            input_fd = open(files[files_index], O_RDONLY);
            //verify the files opend, otherwise we will be in the street :D
            if(input_fd >= 0)
            {
        		//man 2 dup2 to know what its use
                //breifly dup2 closes the file discriptor newfd (who you want to redirect it),
                //and then duplicate the oldfd (my input_fd) with newfd, after that newfd and oldfd are pointing to my opened file
                int newfd =  dup2(input_fd, 0);
                if(newfd == 0)//redirected successfully
                {
                        /*Done*/
                }
                else
                {
                        printf("Failed to redirect input source from file %s\n", files[files_index]);
                }

                

			}
            else
            {
                printf("Failed to open file %s\n", files[files_index]);
            }
            
            files_index++;//go to next file
		}
		//output redirection
       	else if(command[iterator] == '>')
        {
   	       	//open the file you want to be the new output
           	output_fd = open(files[files_index], O_WRONLY | O_CREAT, 0777);//full permissions
           	//verify the file opend, otherwise we will be in the street :D
           	if(output_fd >= 0)
           	{
           		int newfd =  dup2(output_fd, 1);
            	if(newfd == 1)//redirected successfully
	            {
	                /*Done*/
	            }
	            else
	            {
	            	printf("Failed to redirect output to file %s\n", files[files_index]);
				}

    			

            }
          	else
            {
                    printf("Failed to open file %s\n", files[files_index]);
            }
            
            files_index++;//go to next file

        }
		//error redirection
        else if((command[iterator] == '2')&&(command[iterator+1] == '>'))
        {
            //open the file you want to be the new error output
            error_fd = open(files[files_index], O_WRONLY | O_CREAT, 0777);//full permissions
            //verify the file opend, otherwise we will be in the street :D
            if(error_fd >= 0)
            {
               	int newfd =  dup2(error_fd, 2);
                if(newfd == 2)//redirected successfully
                {
                    /*Done*/
                }
                else
                {
                    printf("Failed to redirect error output to file %s\n", files[files_index]);
                }

                

			}
            else
            {
                printf("Failed to open file %s\n", files[files_index]);
            }
            
            files_index++;//go to next file

		}
        else
        {
            /*Nothing*/
        }


        iterator++;//loop on command characters to find redirection chars
	}


}
