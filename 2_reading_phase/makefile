.PHONY: all


ObjPath=../ObjectFiles
SrcPath=./SourceFiles


../Lib/reading.so: $(ObjPath)/begining_ending_spaces_remover.o $(ObjPath)/line_commands_parser.o $(ObjPath)/preprocessor.o
	gcc -shared -fpic -o $@ $^

$(ObjPath)/begining_ending_spaces_remover.o: $(SrcPath)/begining_ending_spaces_remover.c
	@echo "Building $<"
	gcc -o $@ -c $<

$(ObjPath)/line_commands_parser.o: $(SrcPath)/line_commands_parser.c
	@echo "Building $<"
	gcc -o $@ -c $<

$(ObjPath)/preprocessor.o: $(SrcPath)/preprocessor.c
	@echo "Building $<"
	gcc -fpic -o $@ -c $<
