//* Description *//
// Title: Main
// Author: Tyler Reed
// Runs the Program and Interprets the Command Line

//* Libraries *//
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include "Node.h"

//* Namespaces *//
using namespace std;

//* Function Headers *//
// Command Line Methods
int getID(int argc, char* argv[]);
int getLifetime(int argc, char* argv[]);
int getDestination(int argc, char* argv[]);
char* getMessage(int argc, char* argv[]);
vector<int>* getNeighbors(int argc, char* argv[]);
int getDebugLevel(int argc, char* argv[]);

//* Main Method *//
// Runs the Program and Interprets the Command Line
int main(int argc, char* argv[])
{
	// Interpret Command Line Arguments
	int id = getID(argc, argv);
	int lifetime = getLifetime(argc, argv);
	int destination = getDestination(argc, argv);
	string message = getMessage(argc, argv);
	vector<int>* neighbors = getNeighbors(argc, argv);
	int debug = getDebugLevel(argc, argv);

	// Verify Arguments
	if(id < 0)
	{
		cout << "[Node -1] Error: You must specify the Node ID (Use -i <ID>)" << endl;
		return id;
	}
	else if(lifetime < 0)
	{
		cout << "[Node " << id << "] Error: You must specify the Node Lifetime (Use -l <Lifetime>)" << endl;
		return lifetime;
	}
	else if(destination < 0 && message != "")
	{
		cout << "[Node " << id << "] Error: You must specify the Node's Message Destination (Use -d <Destination>)" << endl;
		return destination;
	}
	else if(destination == id)
	{
		cout << "[Node " << id << "] Error: A Node may not send a Message to itself" << endl;
		return destination;
	}
	else if(neighbors == NULL)
	{
		cout << "[Node " << id << "] Error: You must specify the Node's Neighbors (Use -n <Count> <Neighbor 1> ... <Neighbor n>)" << endl;
		return -1;
	}

	// Create the Node
	Node* node = new Node(id, neighbors, debug);

	// Send the Message
	if(message != "")
		node -> sendMessage(message, destination);

	for(int i = 0; i < lifetime; i++)
	{
		node -> run();
		sleep(1);
	}

	// Destroy the Node
	delete node;

	// Destroy the List of Neighbors
	delete neighbors;

	return 0;
}

//* Command Line Methods *//
// Finds and Returns the ID of the Node from the Command Line
int getID(int argc, char* argv[])
{
	for(int i = 0; i < argc - 1; i++)
		if(argv[i][0] == '-' && argv[i][1] == 'i') // Search for '-i' Flag
			return atoi(argv[i + 1]);

	return -1;
}

// Finds and Returns the Lifetime of the Node from the Command Line
int getLifetime(int argc, char* argv[])
{
	for(int i = 0; i < argc - 1; i++)
		if(argv[i][0] == '-' && argv[i][1] == 'l') // Search for '-l' Flag
			return atoi(argv[i + 1]);

	return -1;
}

// Finds and Returns the Message Destination from the Command Line
int getDestination(int argc, char* argv[])
{
	for(int i = 0; i < argc - 1; i++)
		if(argv[i][0] == '-' && argv[i][1] == 'd') // Search for '-d' Flag
			return atoi(argv[i + 1]);

	return -1;
}

// Finds and Returns the Message from the Command Line
char* getMessage(int argc, char* argv[])
{
	for(int i = 0; i < argc - 1; i++)
		if(argv[i][0] == '-' && argv[i][1] == 'm') // Search for '-m' Flag
			return argv[i + 1];

	char null = '\0';
	char* message = &null;
	return message;
}

// Finds and Returns the List of Neighbors from the Command Line
vector<int>* getNeighbors(int argc, char* argv[])
{
	// Initialize Variables
	int count = 0; int index = 0;
	vector<int>* neighbors = new vector<int>();

	for(int i = 0; i < argc; i++)
	{
		// Determine Neighbor Count
		if(count == 0 && i < argc - 2)
		{
			if(argv[i][0] == '-' && argv[i][1] == 'n') // Search for '-n' Flag
			{
				count = atoi(argv[i + 1]);
				index = i + 1;
				i++;
			}
		}
		else if(i <= index + count)
		{
			neighbors -> push_back(atoi(argv[i]));

			if(i == argc - 1)
				return neighbors;
		}
		else
			return neighbors;
	}

	return NULL;
}

int getDebugLevel(int argc, char* argv[])
{
	for(int i = 0; i < argc - 1; i++)
		if(argv[i][0] == '-' && argv[i][1] == 'D') // Search for '-D' Flag
			return atoi(argv[i + 1]);

	return 0;
}
