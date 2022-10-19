.PHONY: clean clean_all

ObjPath=./ObjectFiles
ExecPath=./ExecutableFiles


########################################


$(ExecPath)/FemtoShell_Ext2: $(ObjPath)/main_interface.o ./Lib/reading.so ./Lib/locals.so ./Lib/pipeline.so ./Lib/redirection.so ./Lib/simple.so
	gcc -o $@ $^

$(ObjPath)/main_interface.o:
	cd ./1_main_interface/ && $(MAKE)
	
./Lib/reading.so:	
	cd ./2_reading_phase/ && $(MAKE)
	
./Lib/locals.so:
	cd ./3_local_variables/ && $(MAKE)

./Lib/pipeline.so:
	cd ./4_execution_phase/pipeline/ && $(MAKE)

./Lib/redirection.so:
	cd ./4_execution_phase/redirection/ && $(MAKE)

./Lib/simple.so:
	cd ./4_execution_phase/simple_command/ && $(MAKE)




clean:
	@rm $(ObjPath)/*

clean_all:
	@rm $(ObjPath)/*
	@rm ./Lib/*
	@rm $(ExecPath)/*

