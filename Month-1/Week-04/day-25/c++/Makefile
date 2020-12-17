CC = g++
CFLAGS = -Wall
LDFLAGS = -lpthread

BIN_DIR = bin

main: main.o
	@echo
	@echo Creating ./bin dir...
	@mkdir -p ./$(BIN_DIR)		
	@echo
	@echo Compiling TESTS...
	@$(CC) $(CCFLAGS) -o $(BIN_DIR)/main main.o	$(LDFLAGS)
	
	@echo
	@echo Removing object files...
	@rm *.o

	@echo
	@echo Running tests...
	@./$(BIN_DIR)/main	

clean: 
	@rm -rf $(BIN_DIR)
