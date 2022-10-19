.PHONY: all
ObjPath=../../ObjectFiles
SrcPath=./SourceFiles

../../Lib/redirection.so: $(ObjPath)/get_command_and_files.o $(ObjPath)/input_output_error_redirection_executer.o $(ObjPath)/Redirect_input_output_error.o
	gcc -shared -fpic -o $@ $^

$(ObjPath)/get_command_and_files.o: $(SrcPath)/get_command_and_files.c
	@echo "Building $<"
	gcc  -o $@ -c $<

$(ObjPath)/input_output_error_redirection_executer.o: $(SrcPath)/input_output_error_redirection_executer.c
	@echo "Building $<"
	gcc -fpic -o $@ -c $<

$(ObjPath)/Redirect_input_output_error.o: $(SrcPath)/Redirect_input_output_error.c
	@echo "Building $<"
	gcc  -o $@ -c $<
