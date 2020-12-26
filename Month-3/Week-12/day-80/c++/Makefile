CCX = g++
CXXFLAGS = -g
LDFLAGS = -lpthread

BIN_DIR = bin

main: main.o
	@echo
	@echo Creating ./bin dir...
	@mkdir -p ./$(BIN_DIR)		
	@echo
	@echo Compiling TESTS...
	@$(CCX) $(CXXFLAGS) *.cpp -o $(BIN_DIR)/main $(LDFLAGS)

	@echo
	@echo Removing object files...
	@rm *.o

clean: 
	@rm -rf $(BIN_DIR)

run: main
	@echo
	@echo Running tests...
	@./$(BIN_DIR)/main	
