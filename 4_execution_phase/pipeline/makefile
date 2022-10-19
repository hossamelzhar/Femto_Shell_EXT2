.PHONY: all
ObjPath=../../ObjectFiles
SrcPath=./SourceFiles

../../Lib/pipeline.so: $(ObjPath)/pipeline_commands_geter.o $(ObjPath)/pipeline_executer.o
	gcc -shared -fpic -o $@ $^

$(ObjPath)/pipeline_commands_geter.o: $(SrcPath)/pipeline_commands_geter.c
	@echo "Building $<"
	gcc  -o $@ -c $<

$(ObjPath)/pipeline_executer.o: $(SrcPath)/pipeline_executer.c
	@echo "Building $<"
	gcc  -o $@ -c $<
