.PHONY: all
ObjPath=../ObjectFiles
SrcPath=./SourceFiles

../Lib/locals.so: $(ObjPath)/add_local_var.o $(ObjPath)/display_locals.o $(ObjPath)/export_var.o $(ObjPath)/local_var_parser.o $(ObjPath)/search_var_name.o $(ObjPath)/remove_local_var.o
	gcc -shared -fpic -o $@ $^

$(ObjPath)/add_local_var.o: $(SrcPath)/add_local_var.c
	@echo "Building $<"
	gcc  -o $@ -c $<

$(ObjPath)/display_locals.o: $(SrcPath)/display_locals.c
	@echo "Building $<"
	gcc  -o $@ -c $<

$(ObjPath)/export_var.o: $(SrcPath)/export_var.c
	@echo "Building $<"
	gcc  -o $@ -c $<

$(ObjPath)/local_var_parser.o: $(SrcPath)/local_var_parser.c
	@echo "Building $<"
	gcc  -o $@ -c $<

$(ObjPath)/search_var_name.o: $(SrcPath)/search_var_name.c
	@echo "Building $<"
	gcc  -o $@ -c $<
	
$(ObjPath)/remove_local_var.o: $(SrcPath)/remove_local_var.c
	@echo "Building $<"
	gcc  -o $@ -c $<
		

