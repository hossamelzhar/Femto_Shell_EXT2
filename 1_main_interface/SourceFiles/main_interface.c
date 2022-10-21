#include "../HeaderFiles/main_interface.h"


linked_list_T *MyLocals = NULL; //List Head
int RetStat;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{

	char *user      = NULL;
	char *cwd       = NULL;;
	char line[200];
	char** commands = NULL;
	char *preprocessed_command = NULL;
	char** args = NULL;
	char** command_args = NULL;
	char** files = NULL;
	int  equal_char = 0;
	int  pipeline   = 0;
	int  change_ioe = 0; //change input output error flag
	int  index      = 0;
	int  go_to_next_condition = 1;
	/******************************************************************************************************************************************/
	while(1)
	{
		/**************************user shell input interface***********************************/
		user = getenv("USER");
		cwd  = getcwd(NULL, 0);
		printf("\033[0;32m");//green
		printf("%s@", user);
		printf("\033[0;37m");//white
		printf(":");
		printf("\033[0;36m");//cyan
		printf("%s$ ", cwd);
		printf("\033[0;37m");//white
		//read(0, line, 100);
		gets(line);
		
		/***************************************************************************************/
		
		//remove spaces from begining and return it to line buffer;
		begining_ending_spaces_remover(line);
		
		
		if(line[0]== '\0')//new line
        {
            continue;
        }
		else{}

		//get all commands in command line separated by ';'
		commands = line_commands_parser(line);
		
		index = 0;
		//start execute each command founded in line
		while(commands[index] != NULL)
		{

			//set my flags
			equal_char = 0;  pipeline = 0;  change_ioe = 0;  go_to_next_condition = 1;
			//preprocess command and return it in its memory;
			preprocessed_command = preprocessor_phase(commands[index] , MyLocals, &equal_char, &pipeline, &change_ioe); 
			
			/*********************************************************************************************/	
			if( (1 == pipeline) && (1 == go_to_next_condition) ) //case of we find '|' in line command
			{
				go_to_next_condition = 0;
				pipeline_executer(preprocessed_command);
				
			}
			else{}
			/*********************************************************************************************/
			
			//case of we find '=' char in line command 
			if( (1 == equal_char) && (1 == go_to_next_condition) ) 
			{
				do
				{
					preprocessed_command = local_var_parser(preprocessed_command, &args);
					if( (NULL != args[0]) || (NULL != args[1]) )
					{
						go_to_next_condition = 0;
						add_local_var(&MyLocals, args[0], args[1]);//args[0] -> var name  //args[1] -> var data
						//args[0], args[1], will be freed in add local function, Done
					}
					else//its illegal add local command
					{
						go_to_next_condition = 1;
						break;//do while loop
					}
				}
				while((preprocessed_command != NULL) && (preprocessed_command[0] != '\0'));//while command not finished
			}
			else{}

			if( (1 == change_ioe) && (1 == go_to_next_condition) )//case of we find '<' or '>' in line command
			{
				go_to_next_condition = 0;
				command_args = get_command_and_files(preprocessed_command, &files);
				if( (NULL != command_args) && (NULL != files) )
				{
					input_output_error_redirection_executer(preprocessed_command, command_args, files);
					//free command_args and files in this executer function, Done
				}
				else
				{
					printf("failed to get command arguments to redirect it\n");
				}
			}
			else{}
			
			if(1 == go_to_next_condition)
			{
				simple_command_executer(preprocessed_command, &MyLocals);	
			}
			
			
			index++;

		}//commands loop
		
		//after finishing all commands, free all allocated memory
		index = 0;
		
		while(NULL != commands[index])
        {
        	memset(commands[index], 0, strlen(commands[index]));
            free(commands[index]);
            commands[index] = NULL;
            index++;
        }
		free(preprocessed_command);
		preprocessed_command = NULL;
		free(commands);
		commands = NULL;
		free(cwd);
	}//while(1)

	return 0;
}
