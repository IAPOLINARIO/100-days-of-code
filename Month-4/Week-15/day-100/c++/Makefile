CCX = g++
CXXFLAGS = -g
LDFLAGS = -lpthread
BIN_DIR = bin

main: main.o
	@echo	
	@mkdir -p ./$(BIN_DIR)		

	@echo 
	@echo Calling Netwide Assembler NASM to generate i_o.o from i_o.asm...
	@nasm -f elf64 i_o.asm -o i_o.o
	
	@echo Compiling C++ and linking ASM Object File i_o.o for the tests...
	@$(CCX) $(CXXFLAGS) *.cpp i_o.o -o $(BIN_DIR)/main $(LDFLAGS)
	
	@rm *.o

clean: 
	@rm -rf $(BIN_DIR)

run: main	
	@./$(BIN_DIR)/main	
