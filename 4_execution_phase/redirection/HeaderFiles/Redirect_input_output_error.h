#ifndef REDIR_IN_OUT_ERR_H_
#define REDIR_IN_OUT_ERR_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void Redirect_input_output_error(char command[], char** files);



#endif
