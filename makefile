.PHONY: clean clean_all

ObjPath=./ObjectFiles
ExecPath=./ExecutableFiles
MAINSRC=./1_main_interface/SourceFiles
READSRC=./2_reading_phase/SourceFiles
LOCALSRC=./3_local_variables/SourceFiles
PIPESRC=./4_execution_phase/pipeline/SourceFiles
REDIRSRC=./4_execution_phase/redirection/SourceFiles
SIMPLESRC=./4_execution_phase/simple_command/SourceFiles

########################################


$(ExecPath)/FemtoShell_Ext2: $(ObjPath)/main_interface.o ./Lib/reading.so ./Lib/locals.so ./Lib/pipeline.so ./Lib/redirection.so ./Lib/simple.so
	gcc -o $@ $^

#############################################################################################################################

$(ObjPath)/main_interface.o: $(MAINSRC)/main_interface.c
	[ -d ./ObjectFiles/ ] || mkdir -p ./ObjectFiles/
	[ -d ./Lib/ ] || mkdir -p ./Lib/
	[ -d ./ExecutableFiles/ ] || mkdir -p ./ExecutableFiles/
	@echo "Building $<"
	gcc -o $@ -c $<

#############################################################################################################################	

./Lib/reading.so: $(ObjPath)/begining_ending_spaces_remover.o $(ObjPath)/line_commands_parser.o $(ObjPath)/preprocessor.o
	gcc -shared -fpic -o $@ $^

$(ObjPath)/begining_ending_spaces_remover.o: $(READSRC)/begining_ending_spaces_remover.c
	@echo "Building $<"
	gcc -o $@ -c $<

$(ObjPath)/line_commands_parser.o: $(READSRC)/line_commands_parser.c
	@echo "Building $<"
	gcc -o $@ -c $<

$(ObjPath)/preprocessor.o: $(READSRC)/preprocessor.c
	@echo "Building $<"
	gcc -fpic -o $@ -c $<

##############################################################################################################################

./Lib/locals.so: $(ObjPath)/add_local_var.o $(ObjPath)/display_locals.o $(ObjPath)/export_var.o $(ObjPath)/local_var_parser.o $(ObjPath)/search_var_name.o $(ObjPath)/remove_local_var.o
	gcc -shared -fpic -o $@ $^
	
$(ObjPath)/add_local_var.o: $(LOCALSRC)/add_local_var.c
	@echo "Building $<"
	gcc  -o $@ -c $<

$(ObjPath)/display_locals.o: $(LOCALSRC)/display_locals.c
	@echo "Building $<"
	gcc  -o $@ -c $<

$(ObjPath)/export_var.o: $(LOCALSRC)/export_var.c
	@echo "Building $<"
	gcc  -o $@ -c $<

$(ObjPath)/local_var_parser.o: $(LOCALSRC)/local_var_parser.c
	@echo "Building $<"
	gcc  -o $@ -c $<

$(ObjPath)/search_var_name.o: $(LOCALSRC)/search_var_name.c
	@echo "Building $<"
	gcc  -o $@ -c $<
	
$(ObjPath)/remove_local_var.o: $(LOCALSRC)/remove_local_var.c
	@echo "Building $<"
	gcc  -o $@ -c $<

##############################################################################################################################

./Lib/pipeline.so: $(ObjPath)/pipeline_commands_geter.o $(ObjPath)/pipeline_executer.o
	gcc -shared -fpic -o $@ $^
	
$(ObjPath)/pipeline_commands_geter.o: $(PIPESRC)/pipeline_commands_geter.c
	@echo "Building $<"
	gcc  -o $@ -c $<

$(ObjPath)/pipeline_executer.o: $(PIPESRC)/pipeline_executer.c
	@echo "Building $<"
	gcc  -o $@ -c $<

##############################################################################################################################

./Lib/redirection.so: $(ObjPath)/get_command_and_files.o $(ObjPath)/input_output_error_redirection_executer.o $(ObjPath)/Redirect_input_output_error.o
	gcc -shared -fpic -o $@ $^
	
$(ObjPath)/get_command_and_files.o: $(REDIRSRC)/get_command_and_files.c
	@echo "Building $<"
	gcc  -o $@ -c $<

$(ObjPath)/input_output_error_redirection_executer.o: $(REDIRSRC)/input_output_error_redirection_executer.c
	@echo "Building $<"
	gcc -fpic -o $@ -c $<

$(ObjPath)/Redirect_input_output_error.o: $(REDIRSRC)/Redirect_input_output_error.c
	@echo "Building $<"
	gcc  -o $@ -c $<

##############################################################################################################################

./Lib/simple.so: $(ObjPath)/simple_command_executer.o $(ObjPath)/simple_command_parser.o $(ObjPath)/builtin_command_executer.o $(ObjPath)/external_command_executer.o
	gcc -shared -fpic -o $@ $^

$(ObjPath)/simple_command_executer.o: $(SIMPLESRC)/simple_command_executer.c
	@echo "Building $<"
	gcc  -o $@ -c $<

$(ObjPath)/simple_command_parser.o: $(SIMPLESRC)/simple_command_parser.c
	@echo "Building $<"
	gcc  -o $@ -c $<
	
$(ObjPath)/builtin_command_executer.o: $(SIMPLESRC)/builtin_command_executer.c
	@echo "Building $<"
	gcc  -o $@ -c $<
	
$(ObjPath)/external_command_executer.o: $(SIMPLESRC)/external_command_executer.c
	@echo "Building $<"
	gcc -fpic -o $@ -c $<




clean:
	@rm $(ObjPath)/*

clean_all:
	@rm $(ObjPath)/*
	@rm ./Lib/*
	@rm $(ExecPath)/*

