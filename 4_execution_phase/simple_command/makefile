.PHONY: all
ObjPath=../../ObjectFiles
SrcPath=./SourceFiles

../../Lib/simple.so: $(ObjPath)/simple_command_executer.o $(ObjPath)/simple_command_parser.o $(ObjPath)/builtin_command_executer.o $(ObjPath)/external_command_executer.o
	gcc -shared -fpic -o $@ $^

$(ObjPath)/simple_command_executer.o: $(SrcPath)/simple_command_executer.c
	@echo "Building $<"
	gcc  -o $@ -c $<

$(ObjPath)/simple_command_parser.o: $(SrcPath)/simple_command_parser.c
	@echo "Building $<"
	gcc  -o $@ -c $<
	
$(ObjPath)/builtin_command_executer.o: $(SrcPath)/builtin_command_executer.c
	@echo "Building $<"
	gcc  -o $@ -c $<
	
$(ObjPath)/external_command_executer.o: $(SrcPath)/external_command_executer.c
	@echo "Building $<"
	gcc -fpic -o $@ -c $<
