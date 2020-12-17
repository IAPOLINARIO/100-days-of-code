CC = g++
CFLAGS = -Wall
LDFLAGS = -lssl -lcrypto -lpthread

BIN_DIR = bin

main: main.o
	@echo
	@echo Creating ./bin dir...
	@mkdir -p ./$(BIN_DIR)		
	
	@echo
	@echo Compiling SERVER...
	@$(CC) server.cpp $(CCFLAGS) -o $(BIN_DIR)/server $(LDFLAGS)

	@echo
	@echo Compiling TESTS...
	@$(CC) $(CCFLAGS) -o $(BIN_DIR)/main main.o	$(LDFLAGS)
	
	@echo
	@echo Removing object files...
	@rm *.o

	@echo
	@echo Running SERVER in background...
	@(./$(BIN_DIR)/server &)

	@echo
	@echo Waiting 2s for SERVER startup...
	@sleep 2

	@echo
	@echo Running tests...
	@./$(BIN_DIR)/main	

clean: 
	@rm -rf $(BIN_DIR)
