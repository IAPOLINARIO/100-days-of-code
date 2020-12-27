## TCP/IP Client and Server

At the very high level, there are two actors: a client and a server.

The server has a know IP address that represents a machine to connect to at some point (this address could be retrieved via DNS) and a known port (that represents the service that we want to talk to in that machine).

At this moment, nothing can happen - TCP has its communication based on connections and without some handshaking and connection establishment, no data can be sent. Once the connection gets established, it’s then up to the application to decide whether there’s indeed a server component and a client component. They could be peers and synchronize data back and forth, for instance.

For an application protocol like HTTP/1.1 though, there’s a well-defined client-server model, where a client issues requests with specific methods, and a server that processes these requests and gives back results.

### Echo Server

Create a TCP server that receives incoming messages and echos them back to the sender. It should start by creating a TCP/IP socket connection.

- In the TCP Echo server , we create a socket and bind to a parameterized port number.
- After binding , the process listens for incoming connections.
- Then an infinite loop is started to process the client requests for connections.
- After a connection is requested , it accepts the connection from the client machine and forks a new process.
- The new process receives data from the client and echoes the same data back.
- Please note that this server is capable of handling multiple clients as it forks a new process for every client trying to connect to the server.

### Echo Client

The client program sets up its socket differently from the way a server does. Instead of binding to a port and listening, it uses connect() to attach the socket directly to the remote address.

- In the TCP Echo client a socket is created.
- Using the socket a connection is made to the server.
- After a connection is established , we send messages input from the user and display the data received from the server

### Client and Server Together

The client and server should be run in separate terminal windows, so they can communicate with each other.
