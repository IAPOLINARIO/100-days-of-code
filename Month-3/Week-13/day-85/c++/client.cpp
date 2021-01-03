/**
 * DAY-85 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

#include <netinet/in.h> //for sockaddr_in
#include <unistd.h> //for close 
#include <arpa/inet.h> //for inet_pton

#include <thread> //necessary only for the tests
#include <random> //necessary only for the tests

/**
 * A Socket class for Clients
 */ 
class SocketClient {
	private:
		int port;
		std::string ip;
		int clientSocket;
		bool isConnected;
		int maxBufferSize;
		char *buffer;
	public:	
		SocketClient(const int port, const std::string ip, const int maxBufferSize) {
			this->port = port;
			this->ip = ip;
			this->isConnected = false;
			this->maxBufferSize = maxBufferSize;
			this->buffer = new char[this->maxBufferSize];
		}
		int getID(void) {
			return this->clientSocket;
		}
		bool init(void) {
			//define socket connection address parameters
			sockaddr_in socketAdress;
    		socketAdress.sin_family = AF_INET;
    		socketAdress.sin_port = htons(this->port);
    		inet_pton(AF_INET, this->ip.c_str(), &socketAdress.sin_addr); //convert ip string representation to the sockaddr_in struct

			//create a socket
			this->clientSocket = socket(AF_INET, SOCK_STREAM, 0);
			if (this->clientSocket == -1) {
				return false; //error creating socket
			}			

			//try to connect
			this->isConnected = connect(this->clientSocket, (sockaddr *) &socketAdress, sizeof(socketAdress)) != -1;
			if (!this->isConnected) {
				return false;
			}			

			return true;
		}
		bool disconnect(void) {
			if (!this->isConnected) {
				return true;
			}
			this->isConnected = false;
			return close(this->clientSocket) != -1;
		}
		bool sendMessage(const std::string msg) {
			if (!this->isConnected) {
				return false;
			}
			return send(this->clientSocket, msg.c_str(), msg.size() + 1, 0) != -1; //+1 for null terminator
		}
		bool getMessage(std::string &response) {
			if (!this->isConnected) {
				return false;
			}
			const int bytesReceived = recv(this->clientSocket, this->buffer, this->maxBufferSize, 0);
			if (bytesReceived != -1) {
				response = std::string(this->buffer, bytesReceived);
			}
			return bytesReceived != -1;
		}
		~SocketClient() {
			delete this->buffer;
		}
};

/**
 * Helper method for tests - this will run in a different thread to be able to simulate multiple clients.
 * 
 * @param port Port number to connect
 * @param serverIP Server IP to connect as a string
 * @param maxBufferSize Maximum Buffer Size to read/write content per request
 * @param welcomeMessageFromServer Expected 'Welcome Message' from the Server (to check on tests)
 * @param clientMessage The message from client to be used on tests (and to check the echo feature of the server)
 * @param numberOfMessagesPerClient Number of messages that each client will send/receive to/from server
 * @param clientIntervalBetweenMessages Time interval (in ms) between messages of the client 
 */ 
void testClient(const int port, const std::string serverIP, const int maxBufferSize, const std::string welcomeMessageFromServer, const std::string clientMessage, const int numberOfMessagesPerClient, const int clientIntervalBetweenMessages) {	
	SocketClient client(port, serverIP, maxBufferSize);	
	
	//check for successful init process of the client (including connection)
	CHECK(client.init()); 
	
	std::cout << "Client " << client.getID() << " starting..." << std::endl;
		
	//we expect a 'welcome' message from the server upon connection		
	std::string answerFromServer;
	CHECK(client.getMessage(answerFromServer)); 
	CHECK(answerFromServer == welcomeMessageFromServer);

	//the client sends 'numberOfMessagesPerClient' messages to the server and it is expected to receive a response from each one
	for (size_t i = 0; i < numberOfMessagesPerClient; i++) {
		CHECK(client.sendMessage(clientMessage));				
		CHECK(client.getMessage(answerFromServer)); 
		CHECK(answerFromServer == clientMessage); //we expect echoed messages from the server after the welcome
		std::this_thread::sleep_for(std::chrono::milliseconds(clientIntervalBetweenMessages)); //sleep
	}

	//check for a graceful disconnect from client
	CHECK(client.disconnect());	

	//after disconnection, the client should not be able to send messages	
	CHECK(client.sendMessage(clientMessage) == false);

	std::cout << "Client " << client.getID() << " finished!" << std::endl;
}

/**
 * Tests - Assuming server is up by calling the Makefile...
 */
TEST_CASE("Tests")
{	
	//test parameters
	const int NUMBER_OF_CLIENTS = 1000; //1000 threads
	const int PORT = 8888;
	const int MAX_BUFFER_SIZE = 1025;	
	const int SLEEP_FOR_TEST = 1000; 
	const std::string SERVER_IP = "127.0.0.1";
	const std::string WELCOME_MESSAGE_FROM_SERVER = "Welcome!";
	const std::string CLIENT_MESSAGE = "Test Message!";	
	const int NUMBER_OF_MESSAGES_PER_CLIENT = 2; //number of messages each client will send (so we can check the server response)
	const std::string SHUTDOWN_SERVER = "SHUTDOWN_SERVER\r\n";

	//setup a random number generator (each client will send messages at a random interval)
	std::random_device rd; // only used once to initialise (seed) engine
    std::mt19937 engine(rd());// random-number engine used (Mersenne-Twister in this case)                                          
    std::uniform_int_distribution<int> clientIntervalBetweenMessages(0, SLEEP_FOR_TEST); 

	//to simulate concurrency on the server, each client will run in its own thread
	std::thread clientThreads[NUMBER_OF_CLIENTS];
	for (size_t i = 0; i < NUMBER_OF_CLIENTS; i++) {		
		int interval = clientIntervalBetweenMessages(engine);				
		clientThreads[i] = std::thread(testClient, PORT, SERVER_IP, MAX_BUFFER_SIZE, WELCOME_MESSAGE_FROM_SERVER, CLIENT_MESSAGE, NUMBER_OF_MESSAGES_PER_CLIENT, interval);		
	}
	for (auto &ct : clientThreads) {
		ct.join();
	}	

	std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_FOR_TEST)); //sleep

	//after all clients were processed, a new one will issue the special 'SHUTDOWN_SERVER' 
	//command for a clean shutdown of the server (which is running in background)
	SocketClient client(PORT, SERVER_IP, MAX_BUFFER_SIZE);	

	//check for successful init process of the client (including connection)
	CHECK(client.init()); 
	std::cout << "Final Client " << client.getID() << " starting..." << std::endl;
	
	std::string answerFromServer;
	CHECK(client.getMessage(answerFromServer)); //we expect a 'welcome' message from the server upon connection
	CHECK(answerFromServer == WELCOME_MESSAGE_FROM_SERVER);

	std::cout << "Final Client " << client.getID() << " is going to order a server shutdown..." << std::endl;
	CHECK(client.sendMessage(SHUTDOWN_SERVER));	
}