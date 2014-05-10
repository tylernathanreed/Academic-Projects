//* Description *//
// Title: Network Layer
// Author: Tyler Reed
// Defines the Network Layer of a Node

//* Notes *//
// The Network Layer is responsible for Message Routing
// and Configuration of the Network.
//
// The Network Layer also determines whether or not
// a Message has reached its Destination.

//* Libraries *//
#include "Node.h"

//* Network Layer Methods *//
// Prompts the Network Layer to Update the Root
void Node::Network_checkIfRoot()
{
	debugL(1, "Network | Root", "Checking Root Status\n");

	// Create the Configuration Package
	string package = Network_packageConfigurationMessage(id, 0);

	// Send Configuration Messages to all Neighbors
	for(int i = 0; i < neighbors -> size(); i++)
	{
		// Send the Message to all Channels
		Network_sendToDataLink(package, neighbors -> at(i));
	}
}

// Packages and Returns the specified Configuration Message
string Node::Network_packageConfigurationMessage(int root, int hop_count)
{
	// Configuration Messaages are of the Form:
	// C [1] + Source ID [1] + Root ID [1] + Hop Count [2]

	debugL(2, "Network | Packager", "$f5Packaging Configuration Message {$f0%i$f5, $f0%i$f5}\n", root, hop_count);

	// Create the Package Stream
	stringstream ss;
	ss << "C" << id << root << setw(2) << setfill('0') << hop_count;

	debugL(2, "Network | Packager", "$f5 -> Packaged to '$f0%s$f5'\n", ss.str().c_str());

	// Return the Package
	return ss.str();
}

// Packages and Returns the specified Transport Message
string Node::Network_packageTransportMessage(string message, int destination)
{
	// Network Messages are of the Form:
	// D [1] + Source ID [1] + Destination ID [1] + Payload [From Transport]
	// where the specified Message is the Payload

	debugL(2, "Network | Packager", "$f5Packaging Transport Message {'$f0%s$f5', $f0%i$f5}\n", message.c_str(), destination);

	// Create the Package Stream
	stringstream ss;
	ss << "D" << id << destination << message;

	debugL(2, "Network | Packager", "$f5 -> Packaged to '$f0%s$f5'\n", ss.str().c_str());

	// Return the Package
	return ss.str();
}

// Unpackages a Data Link Message and Returns whether or not the process was Successful
bool Node::Network_unpackageDataLinkMessage(string package, int &source, int &destination, string &message)
{
	// Data Messages are of the Form:
	// Source ID [1] + Destination ID [1] + Payload [From Transport]

	debugL(2, "Network | Unpackager", "$f4Unpackaging Message '$f0%s$f4'\n", package.c_str());

	// Make sure the Package is the Correct Size
	if(package.length() < 2)
		return false;

	// Determine the Source ID
	source = atoi(package.substr(0, 1).c_str());

	// Determine the Destination ID
	destination = atoi(package.substr(1, 1).c_str());

	// Determine the Payload
	message = package.substr(2);

	debugL(2, "Network | Unpackager", "$f4 -> Unpackaged to {Source = $f0%i$f4, Destination = $f0%i$f4, Message = '$f0%s$f4'}\n", source, destination, message.c_str());

	// Unpackaging Successful
	return true;
}

// Unpackages a Network Configuration Message and Returns whether or not the process was Successful
bool Node::Network_unpackageConfigurationMessage(string package, int &source, int &root, int &hop_count)
{
	// Configuration Messages are of the Form:
	// Source ID [1] + Root ID [1] + Hop Count [2]

	debugL(2, "Network | Unpackager", "$f4Unpackaging Message '$f0%s$f4'\n", package.c_str());

	// Make sure the Package is the Correct Size
	if(package.length() != 4)
		return false;

	// Determine the Source ID
	source = atoi(package.substr(0, 1).c_str());

	// Determine the Root ID
	root = atoi(package.substr(1, 1).c_str());

	// Determine the Hop Count
	hop_count = atoi(package.substr(2, 2).c_str());

	debugL(2, "Network | Unpackager", "$f4 -> Unpackaged to {Source = $f0%i$f4, Root = $f0%i$f4, Hop Count = $f0%i$f4}\n", source, root, hop_count);

	// Unpackaging Successful
	return true;
}

// Passes a Message from the Network Layer to the Data Link Layer
void Node::Network_sendToDataLink(string package, int channel)
{
	debugL(3, "Network | Sender", "$f1Sending {Package = '$f0%s$f1', Channel = $f0%i$f1} to Data Link Layer\n", package.c_str(), channel);

	// Call the Data Link Layer's Receiver
	DataLink_receiveFromNetwork(package, channel);
}

// Passes a Message from the Network layer to the Transport Layer
void Node::Network_sendToTransport(string message)
{
	debugL(3, "Network | Sender", "$f1Sending {Message = '$f0%s$f1'} to Transport Layer\n", message.c_str());

	// Call the Transport Layer's Receiver
	Transport_receiveFromNetwork(message);
}

// Called by the Data Link Layer to Handle an Incoming Message
bool Node::Network_receiveFromDataLink(string message, int channel)
{
	debugL(3, "Network | Receiver", "$f2Received {Message = '$f0%s$f2', Channel = $f0%i$f2} from Data Link Layer\n", message.c_str(), channel);

	// Determine the Message Type
	char type = message[0];

	switch(type)
	{
		// Data Link Message
		case 'D':
		{
			// Initialize the Source, Destination, and Payload
			int source = -1; int destination = -1; string payload = "";

			// Unpackage the Data Message
			if(!Network_unpackageDataLinkMessage(message.substr(1), source, destination, payload))
				return false;

			// Determine whether or not the Message has reached its Destination
			if(id == destination)
			{
				// Send the Payload to the Transport Layer
				Network_sendToTransport(payload);
				return true;
			}
			else
			{
				debugL(2, "Network | Receiver", "$f2 -> Passing Message\n");

				// Repackage the Message
				string package = Network_packageTransportMessage(payload, destination);

				// Check if Path is Known
				if(routing_table -> find(destination) != routing_table -> end())
				{
					debugL(3, "Network | Receiver", "$f2 -> Known Path: Sending to Intermediate Node\n");

					// Send the Message to the Next Hop
					Network_sendToDataLink(package, *(routing_table -> at(destination) -> first));
					return true;
				}
				else
				{
					debugL(3, "Network | Receiver", "$f2 -> Unknown Path: Broadcasting to all Children (and Parent)\n");

					// Send the Message to all Children
					for(int i = 0; i < children -> size(); i++)
					{
						// Ignore Source
						if(children -> at(i) == source)
							continue;

						// Send the Message to the Current Child
						Network_sendToDataLink(package, children -> at(i));
					}

					// Send the Message to the Parent
					if(parent != -1 && parent != source)
						Network_sendToDataLink(package, parent);
				}
			}
			break;
		}
		
		// Configuration Message
		case 'C':
		{
			// Initialize the Source, Root and Hop Count
			int source = -1; int root = -1; int hop_count = -1;
	
			// Unpackage the Message
			if(!Network_unpackageConfigurationMessage(message.substr(1), source, root, hop_count))
				return false;

			// Ignore Self
			if(source == id || root == id)
				return true;

			// Update Waittime
			waittime = 0;

			// Increase Hop Count
			hop_count++;

			// Update Routing Table
			if(routing_table -> find(root) == routing_table -> end())
			{
				// Create New Entry
				pair<int*, int*>* entry = new pair<int*, int*>(new int(source), new int(hop_count));

				// Insert into Routing Table
				routing_table -> insert(pair<int, pair<int*, int*>*>(root, entry));

				debugL(1, "Network | Receiver", "$f2Added Routing Table Entry for Node $f0%i$f2 {Channel = $f0%i$f2, Hop Count = $f0%i$f2}\n", root, source, hop_count);
			}
			else
			{
				// Determine Existing Entry
				pair<int*, int*>* entry = routing_table -> at(root);

				// Update Entry if Better
				if(*entry -> second > hop_count)
				{
					*(entry -> first) = channel;
					*(entry -> second) = hop_count;

					debugL(1, "Network | Receiver", "$f2Updated Routing Table Entry $f0%i$f2 to {Channel = $f0%i$f2, Hop Count = $f0%i$f2}\n", root, channel, hop_count);
				}
			}

			// Update Root
			if(this -> root > root)
			{
				debugL(1, "Network | Receiver", "$f2Updated Root from Node $f0%i$f2 to Node $f0%i$f2\n", this -> root, root);
				this -> root = root;

				// Remove Root from Children (if Possible)
				for(int i = 0; i < children -> size(); i++)
					if(children -> at(i) == root)
					{
						debugL(2, "Network | Receiver", "$f2 -> Removed Child Node $f0%i$f2\n", root);
						children -> erase(children -> begin() + i);
						break;
					}

				// Set Root as Parent (if Possible)
				for(int i = 0; i < neighbors -> size(); i++)
					if(neighbors -> at(i) == root)
					{
						debugL(2, "Network | Receiver", "$f2 -> Updated Parent from Node $f0%i$f2 to Node $f0%i$f2\n", parent, root);

						// Add Parent as Child
						if(parent != -1)
						{
							debugL(2, "Network | Receiver", "$f2    -> Added Child Node $f0%i$f2\n", parent);
							children -> push_back(parent);
						}

						parent = root;
						break;
					}
			}

			// Determine Acclaimed Root Entry
			pair<int*, int*>* entry = routing_table -> at(root);

			// Update Parent
			debugL(4, "Network | Receiver", "$f2 -> Parent Check {Root: $f0%i$f2, Hop Count: $f0%i$f2, ID: $f0%i$f2}\n", this -> root == root, *(entry -> second) >= hop_count, (parent > source || parent == -1));

			if(this -> root != root)
				debugL(4, "Network | Receiver", "$f2    -> [Root] Known: $f0%i$f2, Advertised: $f0%i$f2\n", this -> root, root);
			if(*(entry -> second) < hop_count)
				debugL(4, "Network | Receiver", "$f2    -> [Hop Count] Known: $f0%i$f2, Advertised: $f0%i$f2\n", *(entry -> second), hop_count);
			if(parent <= source && parent != -1)
				debugL(4, "Network | Receiver", "$f2    -> [Parent] Known: $f0%i$f2, Advertised: $f0%i$f2\n", parent, source);

			if(this -> root == root && *(entry -> second) >= hop_count && (parent > source || parent == -1)) // Match Root, Hop Count, and ID
			{
				// Make the Parent a Child
				if(parent != -1)
					children -> push_back(parent);

				// Determine the Index of the Parent
				int index = -1;

				for(int i = 0; i < children -> size(); i++)
					if(children -> at(i) == parent)
					{
						index = i;
						break;
					}

				// Delete the Parent from the List of Children
				if(index >= 0)
					children -> erase(children -> begin() + index);

				debugL(2, "Network | Receiver", "$f2Updated Parent from Node $f0%i$f2 to Node $f0%i$f2\n", parent, *(entry -> first));

				// Assign Parent Value
				parent = *(entry -> first);
			}

			// Update Children
			debugL(4, "Network | Receiver", "$f2 -> Child Check {Root: $f0%i$f2, Hop Count $f0%i$f2}\n", this -> root == root, hop_count - 1 == *(entry -> second));

			if(this -> root != root)
				debugL(4, "Network | Receiver", "$f2    -> [Root] Known: $f0%i$f2, Advertised: $f0%i$f2\n", this -> root, root);
			if(hop_count - 1 != *(entry -> second))
				debugL(4, "Network | Receiver", "$f2    -> [Hop Count] Known: $f0%i$f2, Advertised: $f0%i$f2\n", hop_count - 1, *(entry -> second));

			if(this -> root == root && hop_count - 1 == *(entry -> second))
			{
				// Determine the Index of the Child
				int index = -1;

				for(int i = 0; i < children -> size(); i++)
					if(children -> at(i) == source)
					{
						index = i;
						break;
					}

				// Make sure the Source is a Child
				if(index >= 0)
				{
					// Delete the Child from the List of Children
					children -> erase(children -> begin() + index);
					debugL(2, "Network | Receiver", "$f2Removed Child Node $f0%i$f2\n", source);
				}
			}

			// Root does not Transfer Broadcasts
			if(id != this -> root)
			{
				// Broadcast Configuration Message
				for(int i = 0; i < children -> size(); i++)
				{
					// Ignore Source (Should Never Happen)
					if(children -> at(i) == source)
						continue;

					// Package Configuration Message
					string package = Network_packageConfigurationMessage(root, hop_count);

					// Send the Package to the Data Link Layer
					Network_sendToDataLink(package, children -> at(i));
				}
				}
			break;
		}

		// Unknown Message
		default:
			debugL(1, "Network | Receiver", "$f2 -> Unknown Package Type '$f0%c$f2'\n", type);
			return false;
	}
}

// Called by the Transport Layer to Handle an Outgoing Message
void Node::Network_receiveFromTransport(string message, int destination)
{
	debugL(3, "Network | Receiver", "$f2Received {Message = '$f0%s$f2', Destination = $f0%i$f2} from Transport Layer\n", message.c_str(), destination);

	// Package the Message
	string package = Network_packageTransportMessage(message, destination);

	// Check if Path is Known
	if(routing_table -> find(destination) != routing_table -> end())
	{
		debugL(3, "Network | Receiver", "$f2 -> Known Path: Sending to Intermediate Node\n");

		// Send the Message to the Next Hop
		Network_sendToDataLink(package, *(routing_table -> at(destination) -> first));
	}
	else
	{
		debugL(3, "Network | Receiver", "$f2 -> Unknown Path: Broadcasting to all Neighbors\n");

		// Send the Message to all Neighbors
		for(int i = 0; i < neighbors -> size(); i++)
		{
			// Send the Message to the Current Neighbor
			Network_sendToDataLink(package, neighbors -> at(i));
		}
	}
}
