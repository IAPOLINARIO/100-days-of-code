/**
 * DAY-85 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

#include <unistd.h> //for close 
#include <arpa/inet.h> //for inet_ntoa 
#include <fcntl.h> //for fcntl

/**
 * A Socket class for Server
 * Single thread implementation using the 'select' strategy.
 */ 
class SocketServer {
	private:
		const std::string SHUTDOWN_SERVER = "SHUTDOWN_SERVER\r\n"; //reserved command to shutdown the server from the client
		int port;
		int maxConnectionQueueBeforeRefuse;		
		std::string welcomeMessage;
		int masterSocketId; //hold the Master Socket ID	
		fd_set socketDescriptorsSet; //set of socket descriptors 	
		std::vector<int> clientSockets; //list of connected client sockets	
		bool outputLog;		

		struct SocketInfo {
			int id;
			char *ip;
			uint16_t port;
			bool connected;
		} socketInfoHolder;

		struct Message {
			int socketId; //origin
			int socketIdPosition; //position on the list of connected clients
			int size; //size of the message		
			int maxBufferSize;	
			char *buffer; //buffer			
			enum { DISCONNECT, NORMAL, CANT_WAIT, ERROR } type;
			Message(int maxBufferSize) {
				this->maxBufferSize = maxBufferSize;
				this->buffer = new char[this->maxBufferSize];		
			}
			~Message() {
				delete this->buffer;
			}
		} *messageHolder;

		bool setupMasterSocketId(void) {
			//create Master Socket Id
			this->masterSocketId = socket(AF_INET , SOCK_STREAM , 0);
			if (!this->masterSocketId) {
				return false;
			}
			//Set Master Socket Id to allow multiple connections.
			int opt;
			if (setsockopt(this->masterSocketId, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
				return false;
			}
			//Bind the Master Socket Id to a port 
			sockaddr_in socketAdress; //a socket address struct				
			socketAdress.sin_family = AF_INET; 
			socketAdress.sin_addr.s_addr = INADDR_ANY; 
			socketAdress.sin_port = htons(this->port); 	
			if (bind(this->masterSocketId, (sockaddr *) &socketAdress, (socklen_t) sizeof(socketAdress)) < 0) { 				
				return false;
			} 			
			//Setup listener for Master Socket Id
			if (listen(this->masterSocketId, this->maxConnectionQueueBeforeRefuse) < 0) { 
				return false;
			}			
			return true;
		}
		bool isIncomingConnection(void) {
			return FD_ISSET(masterSocketId, &this->socketDescriptorsSet); //If something happened on the master socket, then its an incoming connection
		}		
		SocketInfo* getSocketInfo(const int socketId, const bool connected = true, sockaddr_in* socketAdress = nullptr) {			
			char *ipAux;
			uint16_t portAux;

			if (socketAdress == nullptr) { 
				sockaddr_in socketAdressAux;
				int socketAdressAuxSize = sizeof(socketAdressAux);
				getpeername(socketId, (struct sockaddr*) &socketAdressAux, (socklen_t*) &socketAdressAuxSize);
				ipAux = inet_ntoa(socketAdressAux.sin_addr);
				portAux = ntohs(socketAdressAux.sin_port);
			} else { //avoid calling function getpeername if the socketAdress strucuture is already defined (for some cases)
				ipAux = inet_ntoa(socketAdress->sin_addr);
				portAux = ntohs(socketAdress->sin_port);
			}

			this->socketInfoHolder.id = socketId;
			this->socketInfoHolder.ip = ipAux;
			this->socketInfoHolder.port = portAux;
			this->socketInfoHolder.connected = connected;
			
			return &this->socketInfoHolder;
		}
		void output(const std::string o) {
			if (this->outputLog) {
				std::cout << o << std::endl;
			}
		}
		void outputSocketConnectionStatus(SocketInfo *socketInfo) {			
			std::string o = "Socket ID: " + std::to_string(socketInfo->id) + ", IP: " + socketInfo->ip + ", Port: " + std::to_string(socketInfo->port) + ", Status: " + (socketInfo->connected ? "connected" : "disconnected");
			this->output(o);
		}
		bool sendMessage(const int socketId, const std::string msg) {
			const size_t msgSize = msg.size();
			return send(socketId, msg.c_str(), msgSize, 0) == msgSize;
		}
		bool addNewClient(void) {
			//create new client socket			
			sockaddr_in socketAdress; //struct to be filled by accept
			int socketAdressSize = sizeof(socketAdress);
			int clientSocketId = accept(this->masterSocketId, (sockaddr*) &socketAdress, (socklen_t*) &socketAdressSize);
			if (clientSocketId < 0) {
				return false;
			}						
			fcntl(clientSocketId, F_SETFL, O_NONBLOCK); //set client socket as non blocking
			FD_SET(clientSocketId, &socketDescriptorsSet); //add client socket to the Socket Descriptors Set						
			this->clientSockets.push_back(clientSocketId); //add new socket to array of sockets 
									
			if (!this->sendMessage(clientSocketId, this->welcomeMessage)) {//send new connection greeting message to the client
				return false;
			}						
			this->outputSocketConnectionStatus(this->getSocketInfo(clientSocketId, true, &socketAdress)); //log new client socket connection information on the server			
			return true;
		}
		Message* readMessage(const int socketId, const int position) {
			this->messageHolder->socketId = socketId;
			this->messageHolder->socketIdPosition = position;
			this->messageHolder->size = read(socketId, this->messageHolder->buffer, this->messageHolder->maxBufferSize);
					
			if (this->messageHolder->size  == 0) {
				this->messageHolder->type = Message::DISCONNECT;
			} else {
				if (this->messageHolder->size  > 0) {
					this->messageHolder->buffer[this->messageHolder->size] = '\0'; //set the string terminating NULL byte on the end of the data read
					this->messageHolder->type = Message::NORMAL;
				} else {
					if (this->messageHolder->size  == -1 && (errno == EWOULDBLOCK)) {
						this->messageHolder->type = Message::CANT_WAIT;
					} else {
						this->messageHolder->type = Message::ERROR;
					}
				}
			}			
			return this->messageHolder;
		}
		bool disconnect(int socketId, int position) {
			this->outputSocketConnectionStatus(this->getSocketInfo(socketId, false)); //output socket status - disconnect
			int r = close(socketId); //Close the socket
			FD_CLR(socketId, &this->socketDescriptorsSet); //remove from the sockets descriptors set 
			this->clientSockets.erase(clientSockets.begin() + position); //remove from the list
			return r != -1;
		}
		bool shutdown(void) {
			this->output("Shutting down server!");
			//try to gracefully disconnect all connected clients before server shutdown
			for (int i = this->clientSockets.size() -1; i >= 0; i--) {
				this->output("Trying to disconnect client "  + std::to_string(this->clientSockets[i]) +  "...");
				if (!this->disconnect(this->clientSockets[i], i)) {
					this->output("There was an error trying to disconnect client "  + std::to_string(this->clientSockets[i]));
					return false; //error trying to disconnect client, return a 'bad' shutdown
				}
				this->output("Client "  + std::to_string(this->clientSockets[i]) +  " disconnected!");
			}
			return true; //clean shutdown
		}
	public:
		SocketServer(const int port, const int maxBufferSize, const int maxConnectionQueueBeforeRefuse, const std::string welcomeMessage, const bool outputLog) {
			this->port = port;
			this->maxConnectionQueueBeforeRefuse = maxConnectionQueueBeforeRefuse;			
			this->welcomeMessage = welcomeMessage;
			this->messageHolder = new SocketServer::Message(maxBufferSize);						
			this->outputLog = outputLog;
		}
		bool init() {
			FD_ZERO(&this->socketDescriptorsSet); //clear the socket set						
			return this->setupMasterSocketId();
		}
		int updateSocketDescriptors(void) {
			FD_ZERO(&socketDescriptorsSet);				
			FD_SET(this->masterSocketId, &this->socketDescriptorsSet); 	//add Master Socket Id to Socket Descriptors Set			
			int highestSocketDescriptor = this->masterSocketId;
			for (auto &c : this->clientSockets) {					
				FD_SET(c, &socketDescriptorsSet);
				if (c > highestSocketDescriptor) {
					highestSocketDescriptor = c;
				}
			}
			return highestSocketDescriptor;
		}
		bool processConnections(void) {						
			while(true) {				
				//wait here for any signal of activity using the Socket Descriptors Set
				select(this->updateSocketDescriptors() + 1, &socketDescriptorsSet, NULL , NULL , NULL);		

				//check if there are messages from already connected clients, handle them
				for (int i = clientSockets.size() -1; i >= 0; i--) { //check the list of connected client sockets		
					if (FD_ISSET(clientSockets[i], &socketDescriptorsSet)) {  //check if where was set an activity for this client						
						Message *message = this->readMessage(clientSockets[i], i);
						switch (message->type)
						{
						case Message::DISCONNECT: 
							if (!this->disconnect(message->socketId, message->socketIdPosition)) { //disconnect the client
								this->output("Error disconnecting client " + std::to_string(message->socketId));
								return false;
							} 
							break;
						case Message::NORMAL: 				
							if ((std::string) message->buffer == this->SHUTDOWN_SERVER) { //special message to the server: SHUTDOWN_SERVER
								return this->shutdown(); //shutdown the server!					
							} else {
								if (!this->sendMessage(message->socketId, message->buffer)) { //just echo the message back to client!
									return false;
								}
								break;
							}									
						case Message::CANT_WAIT:
							this->output("Can't wait to read the client socket (" + std::to_string(message->socketId) + "). Operation would block!");
							break;							
						default:
							this->output("Error reading client socket (" + std::to_string(message->socketId) + ") message");
							return false;							
						}	
					}
				}	

				if (this->isIncomingConnection()) {
					if (!this->addNewClient()) {						
						return false; //error adding new client
					}
				}					
			}
		}
		~SocketServer() {
			delete this->messageHolder;			
		}
};

/**
 * Tests
 */
TEST_CASE("Tests")
{	
	//test parameters
	const int PORT = 8888;
	const int MAX_BUFFER_SIZE = 1025;
	const int MAX_CONNECTION_QUEUE_BEFORE_REFUSE = 1000;		
	const std::string WELCOME_MESSAGE_FROM_SERVER = "Welcome!";	
	const bool OUTPUT_LOG = true;	

	SocketServer server(PORT, MAX_BUFFER_SIZE, MAX_CONNECTION_QUEUE_BEFORE_REFUSE, WELCOME_MESSAGE_FROM_SERVER, OUTPUT_LOG);
	CHECK(server.init()); //check initialization (including connection)
	CHECK(server.processConnections());	//check for a 'clean shutdown'
}