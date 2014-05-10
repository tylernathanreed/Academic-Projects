//* Description *//
// Title: Node
// Author: Tyler Reed
// Simulates an Internet Node

//* Notes *//
// A Node is Split into 3 Layers:
// - Data Link (Responsible for Channel I/O)
// - Network (Responsible for Message Routing)
// - Transport (Responsible for End-to-End Communication)

// Methods are split into 3 Categories:
// - Personal (Contains Methods required to perform own Tasks)
// - Package/Unpackage (Contains Methods for Adding/Removing Layers to Messages)
// - Send/Receive (Contains Methods for Sending/Receiving Messages from other Layers)

//* Header Declaration *//
#ifndef H_NODE
#define H_NODE

//* Definitions *//
#define LIMIT_NODE 10
#define LIMIT_WINDOW 5
#define CONFIG_ROOT 5
#define CONFIG_TIMEOUT 20
#define MESSAGE_TIMEOUT 5

//* Libraries *//
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <stdarg.h>
#include <vector>
#include <queue>
#include <map>
#include "Reader.h"
#include "Writer.h"
#include "Debug.h"

//* Namespaces *//
using namespace std;

//* Type Definitions *//
typedef map<int, map<int, string*>*>::iterator it_mimis;
typedef map<int, pair<int*, int*>*>::iterator it_mipii;
typedef map<int, pair<int, int*>*>::iterator it_mipii2;
typedef map<int, string*>::iterator it_mis;
typedef map<int, Reader*>::iterator it_mir;
typedef map<int, Writer*>::iterator it_miw;

//* Node Class *//
class Node
{
	//* Class Variables *//
	// Private Variables
	private:
		// Node Variables
		int id;						// ID of the Node
		int lifetime;					// Lifetime (in Seconds) of the Node
		int waittime;					// Waittime (in Seconds) after a Root Message

		// Topology Variables
		int root;					// ID of the Root of the Network
		int parent;					// ID of the Parent of the Node
		vector<int>* neighbors;				// List of Neighbor IDs
		vector<int>* children;				// List of Children IDs
		map<int, pair<int*, int*>*>* routing_table;	// Routing Table that Maps by <Node ID> -> <Channel, Hop Count>

		// Message Variables
		queue<pair<int, string*>*>* send_buffer;	// Send Buffer that contains Queued Partial Messages (Popped on Next Runtime)
		map<int, map<int, string*>*>* sent;		// Sent Buffer that Maps by <Node ID> -> <Sequence, Message>
		map<int, map<int, string*>*>* received;		// Received Buffer that Maps by <Node ID> -> <Sequence, Message>
		map<int, int*>* expected;			// Expectation Table that Maps by <Node ID> -> <Next Sequence Expected>
		map<int, int*>* timeout;			// Timeout Table that Maps by <Node ID> -> <Receive Timestamp>

		// Channel Variables
		map<int, string*>* buffer;			// Stores non-partitioned Data read from the Indexed Channels
		map<int, Reader*>* readers;			// List of Channel Readers (from[X]to[ID])
		map<int, Writer*>* writers;			// List of Channel Writers (from[ID]to[X])

		// Debug Variables
		Debug* debugger;				// Used to Test the Program

	//* Class Methods *//
	// Public Methods
	public:
		// Constructors and Deconstructor
		Node(int id, vector<int>* neighbors, int debug_mode = 0);
		~Node();

		// Simulation Methods
		void run();

		// Messaging Methods
		void sendMessage(string message, int destination);

	// Private Methods
	private:
		//* Node Methods *//
		// Memory Management Methods
		void initialize();
		void deinitialize();

		//* Data Link Methods *//
		// Personal Methods
		string DataLink_readFromChannel(int channel);
		void DataLink_writeToChannel(string data, int channel);

		int DataLink_getCheckSum(string message);

		// Packaging/Unpackaging Methods
		string DataLink_packageNetworkMessage(string message);
		bool DataLink_unpackageChannelMessage(string package, string &message);

		// Sending/Receiving Methods
		void DataLink_sendToChannel(string message, int channel);
		void DataLink_sendToNetwork(string message, int channel);
		bool DataLink_receiveFromChannel(string data, int channel);
		void DataLink_receiveFromNetwork(string package, int channel);

		//* Network Layer Methods *//
		// Personal Methods
		void Network_checkIfRoot();

		// Packaging/Unpackaging Methods
		string Network_packageConfigurationMessage(int root, int hop_count);
		string Network_packageTransportMessage(string message, int destination);

		bool Network_unpackageDataLinkMessage(string package, int &source, int &destination, string &message);
		bool Network_unpackageConfigurationMessage(string package, int &source, int &root, int &hop_count);

		// Sending/Receiving Methods
		void Network_sendToDataLink(string package, int channel);
		void Network_sendToTransport(string message);

		bool Network_receiveFromDataLink(string message, int channel);
		void Network_receiveFromTransport(string package, int destination);

		//* Transport Layer Methods *//
		// Personal Methods
		void Transport_sendMessage(string message, int destination);
		void Transport_receiveMessage(string message, int source, int sequence);
		void Transport_sendAcknowledgement(int source, int destination);

		// Packaging/Unpackaging Methods
		string Transport_packagePartialMessage(string message, int destination, int sequence);
		string Transport_packageAcknowledgement(int destination, int sequence);

		bool Transport_unpackagePartialMessage(string package, int &source, int &sequence, string &message);
		bool Transport_unpackageAcknowledgement(string package, int &source, int &sequence);

		// Sending/Receiving Methods
		void Transport_sendToNetwork(string package, int destination);
		bool Transport_receiveFromNetwork(string message);

		//* Debug Methods *//
		void debug(int access, string message, ...);
		void debugL(int access, string layer, string message, ...);
		void printRoutingTable();
};

//* Node Methods *//
// Creates an Instance of the Node Class given the ID, Lifetime, and Neighbors of the Node
inline Node::Node(int id, vector<int>* neighbors, int debug_mode)
{
	// Copy Parameters
	this -> id = id;
	this -> neighbors = neighbors;
	this -> debugger = new Debug(debug_mode);

	debug(3, "Node Created\n");

	// Initialize all Variables
	initialize();

	// Fill the Routing Table with Known Information
	for(int i = 0; i < neighbors -> size(); i++)
	{
		debug(4, "Creating Routing Table Entry: %i -> %i, %i\n", neighbors -> at(i), neighbors -> at(i), 1);

		pair<int*, int*>* entry = new pair<int*, int*>(new int(neighbors -> at(i)), new int(1));

		routing_table -> insert(pair<int, pair<int*, int*>*>(neighbors -> at(i), entry));
	}

	// Print Routing Table
	if(debug_mode > 3)
	{
		debug(0, "Initial Routing Table\n");
		printRoutingTable();
	}

	// Assume Root Status and Broadcast
	Network_checkIfRoot();
}

// Safely Destroys the Node Instance
inline Node::~Node()
{
	// Determine the File Path
	stringstream ss;
	ss << "Output/node" << id << "received.txt";

	// Create the Writer
	Writer* writer = new Writer(ss.str().c_str());

	debug(1, "Writing Received Messages to File ('$f1%s$f0')\n", ss.str().c_str());

	// Write the Messages Received from all Nodes
	for(int i = 0; i < LIMIT_NODE; i++)
	{
		// Skip Self
		if(i == id)
			continue;

		// Create the Write Stream
		stringstream output;
		output << "Message Received from Node " << i << ": '";

		// Determine the Received Map
		map<int, string*>* rcv = received -> at(i);

		// Skip Empty Messages
		if(rcv -> size() == 0)
			continue;

		// Print out the Messages in Order
		for(int j = 0; j < rcv -> size(); j++)
			output << *(rcv -> at(j));

		output << "'" << endl;

		writer -> writeMessage(output.str());
		debug(1, " -> Writing '$f1%s$f0'\n", output.str().substr(0, output.str().length() - 1).c_str());
	}

	delete writer;

	// Print Topology Knowledge
	debug(2, "Topology:\n");
	debug(2, " -> Root: $f1%i$f0\n", root);
	debug(2, " -> Parent: $f1%i$f0\n", parent);
	debug(2, " -> Children:\n");

	for(int i = 0; i < children -> size(); i++)
		debug(2, "    -> [$f1%i$f0]: $f1%i$f0\n", i, children -> at(i));

	debug(2, " -> Routing Table:\n");

	for(map<int, pair<int*, int*>*>::iterator iterator = routing_table -> begin(); iterator != routing_table -> end(); iterator++)
	{
		pair<int*, int*>* entry = iterator -> second;

		debug(2, "    -> Node $f1%i$f0 -> Channel: $f1%i$f0, Hop Count: $f1%i$f0\n", iterator -> first, *(entry -> first), *(entry -> second));
	}

	deinitialize();

	debug(3, "Node Destroyed\n");

	delete debugger;
}

//* Memory Management Methods *//
// Initializes all Class Variables
inline void Node::initialize()
{
	// Node Variables
	lifetime = 0;
	waittime = 0;

	// Topology Variables
	root = id;
	parent = -1;
	routing_table = new map<int, pair<int*, int*>*>();
	children = new vector<int>();

	for(int i = 0; i < neighbors -> size(); i++)
		children -> push_back(neighbors -> at(i));

	// Message Variables
	send_buffer = new queue<pair<int, string*>*>();
	sent = new map<int, map<int, string*>*>();
	received = new map<int, map<int, string*>*>();
	expected = new map<int, int*>();
	timeout = new map<int, int*>();

	// Channel Variables
	buffer = new map<int, string*>();
	readers = new map<int, Reader*>();
	writers = new map<int, Writer*>();

	// Create Channel Readers and Writers
	for(int i = 0; i < LIMIT_NODE; i++)
	{
		// Skip Self
		if(i == id)
			continue;

		// Determine the File Names
		stringstream rss, wss;
		rss << "./Channels/from" << i << "to" << id << ".txt";
		wss << "./Channels/from" << id << "to" << i << ".txt";

		// Create Reader and Writer
		Reader* reader = new Reader(rss.str().c_str());
		Writer* writer = new Writer(wss.str().c_str());

		// Map the Reader and Writer
		readers -> insert(pair<int, Reader*>(i, reader));
		writers -> insert(pair<int, Writer*>(i, writer));

		// Insert Empty Buffers
		buffer -> insert(pair<int, string*>(i, new string("")));

		// Initialize Expectations and Timeouts
		expected -> insert(pair<int, int*>(i, new int(0)));

		// Insert Send and Received Maps
		sent -> insert(pair<int, map<int, string*>*>(i, new map<int, string*>()));
		received -> insert(pair<int, map<int, string*>*>(i, new map<int, string*>()));
	}
}

// Destroys all Class Variables
inline void Node::deinitialize()
{
	debug(4, "Destroying Class Variables\n");

	// Topology Variables
	for(it_mipii iterator = routing_table -> begin(); iterator != routing_table -> end(); iterator++)
	{
		delete (iterator -> second -> first);
		delete (iterator -> second -> second);
		delete (iterator -> second);
	}

	delete routing_table;

	debug(4, " -> Routing Table Destroyed\n");

	//delete neighbors;

	debug(4, " -> Neighbors Destroyed\n");

	// Message Variables
	while(send_buffer -> size() > 0)
	{
		delete (send_buffer -> front());
		send_buffer -> pop();
	}

	delete send_buffer;

	debug(4, " -> Send Buffer Destroyed\n");

	for(it_mimis iterator = sent -> begin(); iterator != sent -> end(); iterator++)
		delete (iterator -> second);

	delete sent;

	debug(4, " -> Sent Map Destroyed\n");

	for(it_mimis iterator = received -> begin(); iterator != received -> end(); iterator++)
		delete (iterator -> second);

	delete received;

	debug(4, " -> Received Map Destroyed\n");

	for(map<int, int*>::iterator iterator = expected -> begin(); iterator != expected -> end(); iterator++)
		delete (iterator -> second);

	delete expected;

	debug(4, " -> Expected Map Destroyed\n");

	for(map<int, int*>::iterator iterator = timeout -> begin(); iterator != timeout -> end(); iterator++)
		delete (iterator -> second);

	delete timeout;

	debug(4, " -> Timout Map Destroyed\n");

	// Channel Variables
	for(it_mis iterator = buffer -> begin(); iterator != buffer -> end(); iterator++)
		delete (iterator -> second);

	delete buffer;

	debug(4, " -> Buffer Destroyed\n");

	for(it_mir iterator = readers -> begin(); iterator != readers -> end(); iterator++)
		delete (iterator -> second);

	delete readers;

	debug(4, " -> Readers Destroyed\n");

	for(it_miw iterator = writers -> begin(); iterator != writers -> end(); iterator++)
		delete (iterator -> second);

	delete writers;

	debug(4, " -> Writers Destroyed\n");
}

//* Simulation Methods *//
// Simulates a Frame of the Node
inline void Node::run()
{
	lifetime++;

	debug(1, "Running at Lifetime: $f1%i$f0\n", lifetime);

	// Read Everything
	for(int i = 0; i < LIMIT_NODE; i++)
	{
		// Skip Self
		if(i == id)
			continue;

		// Determine the Existing Buffer
		string* bp = buffer -> at(i);

		// Read from the Channel
		string received = DataLink_readFromChannel(i);

		// Make sure something was Read
		if(received == "" && *bp == "")
			continue;

		// Determine the Full Buffer
		string old = *bp;
		*bp += received;

		debug(3, "Starting Buffer: '$f1%s$f0' ('$f1%s$f0' + '$f1%s$f0')\n", (*bp).c_str(), old.c_str(), received.c_str());

		// Try to Send it to the Data Link Layer
		while((*bp).length() > 0 && DataLink_receiveFromChannel(*bp, i))
		{
			// Determine what to remove from the Buffer
			int size = atoi((*bp).substr(1, 2).c_str());
			*bp = (*bp).substr(size);

			debug(3, "Remaining Buffer: '$f1%s$f0' (Removed $f1%i$f0 Characters)\n", (*bp).c_str(), size);
			debug(4, " -> Pointer: $f1%i$f0 ('$f1%s$f0')\n", buffer -> at(i), (*(buffer -> at(i))).c_str());
		}

		if((*bp).length() > 0) // Invalid Message
		{
			// Check Type
			char type = (*bp)[0];

			switch(type)
			{
				case 'S': // Correct Type
				{
					// Determine the Size of the Message
					int size = atoi((*bp).substr(1, 2).c_str());

					// Check for Corrupted Size or Checksum
					if((*bp).length() >= size)
					{
						// Determine Index of Next Message
						int index = (*bp).find('S', 1);

						// Strip Bad Message
						if(index > 0)
							*bp = (*bp).substr(index);
						else // Nothing Useful Remains
							*bp = ""; // Clear Buffer
					}
					//else 
					//{
					//	// Full Message has not Arrived, just wait.
					//}

					break;
				}
				default: // Incorrect Type
				{
					// Determine Index of Next Message
					int index = (*bp).find('S', 1);

					// Strip Bad Message
					if(index > 0)
						*bp = (*bp).substr(index);
					else // Nothing Useful Remains
						*bp = ""; // Clear Buffer

					break;
				}
			}
		}
	}

	// Propogate Root Broadcast
	if(lifetime % CONFIG_ROOT == 0 && root == id)
		Network_checkIfRoot();
	// Empty Sent Buffer
	else if(send_buffer -> size() > 0)
	{
		// Determine the Next Packaged Partial Message
		pair<int, string*>* entry = send_buffer -> front();
		send_buffer -> pop();

		// Send the Message to the Network Layer
		Transport_sendToNetwork(*(entry -> second), entry -> first);

		// Destroy the Entry
		delete entry;
	}

	// Send Negative Acknowledgements
	if(lifetime >= MESSAGE_TIMEOUT)
	{
		// Check all Timeouts
		for(map<int, int*>::iterator iterator = timeout -> begin(); iterator != timeout -> end(); iterator++)
		{
			// Determine Expected Value
			int exp = *(iterator -> second);

			debug(3, "Timout Check for Node $f1%i$f0: $f1%i$f0\n", iterator -> first, *(iterator -> second));

			// Determine whether or not a Timeout has Occurred
			if(lifetime > exp)
			{
				// Determine the Source
				int source = iterator -> first;

				// Send a Negative Acknowledgement
				Transport_sendAcknowledgement(source, *(expected -> at(source)));
			}
		}
	}

	// Assume Root Status
	if(waittime >= CONFIG_TIMEOUT && root != id)
	{
		this -> root = id;
		Network_checkIfRoot();
		waittime = 0;
	}
	else if(root != id)
		waittime++;
}

//* Messaging Methods *//
// Sends a Message to the specified Node
inline void Node::sendMessage(string message, int destination)
{
	debug(1, "Sending Message '$t1%s$t0' to Node $f1%i$f0\n", message.c_str(), destination);

	// Call the Transport Layer's Sender
	Transport_sendMessage(message, destination);
}

//* Debug Methods *//
// Prints a Debug Message to the Console
inline void Node::debug(int access, string message, ...)
{
	va_list args;
	va_start(args, message);
	va_end(args);

	stringstream prefix;
	prefix << "[$f" << (id % 6 + 1) << "Node " << id << "$f0] " << message;

	debugger -> debug(access, prefix.str(), args);
}

// Prints a Debug Message from the specified Layer to the Console
inline void Node::debugL(int access, string layer, string message, ...)
{
	va_list args;
	va_start(args, message);
	va_end(args);

	stringstream prefix;
	prefix << "[$f" << (id % 6 + 1) << "Node " << id << " | " << layer << "$f0] " << message;

	debugger -> debug(access, prefix.str(), args);
}

// Prints the Routing Table
inline void Node::printRoutingTable()
{
	for(it_mipii iterator = routing_table -> begin(); iterator != routing_table -> end(); iterator++)
	{
		// Determine the Entry
		pair<int*, int*>* entry = iterator -> second;

		cout << "\tNode: " << iterator -> first << " -> Channel: " << *(entry -> first) << ", Hop Count: " << *(entry -> second) << endl;
	}
}
//* End of Header Declaration *//
#endif
