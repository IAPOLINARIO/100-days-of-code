CCX = g++
CXXFLAGS = -g
LDFLAGS = -lpthread

BIN_DIR = bin

main: server.o
	@echo
	@echo Creating ./bin dir...
	@mkdir -p ./$(BIN_DIR)		

	@echo
	@echo Compiling SERVER...
	@$(CCX) $(CXXFLAGS) server.cpp -o $(BIN_DIR)/server

	@echo Compiling CLIENT...
	@$(CCX) $(CXXFLAGS) client.cpp -o $(BIN_DIR)/client $(LDFLAGS)

	@echo
	@echo Removing object files...
	@rm *.o

clean: 
	@rm -rf $(BIN_DIR)

run: main
	@echo
	@echo Running tests...
	@echo

	@echo Running SERVER in background...
	@(./$(BIN_DIR)/server &)

	@echo
	@echo Waiting 2s for SERVER startup...
	@sleep 2

	@echo Running CLIENTS...
	@./$(BIN_DIR)/client	
