//* Description *//
// Title: Reader
// Author: Tyler Reed
// Reads Input from File

//* Header Definition *//
#ifndef H_READER
#define H_READER

//* Libraries *//
#include <stdio.h>
#include <fcntl.h>
#include <string>

//* Namespaces *//
using namespace std;

//* Reader Class *//
class Reader
{
	//* Class Variables *//
	// Private Variables
	private:
		int file;

	//* Class Methods *//
	// Public Methods
	public:
		// Constructor
		Reader(const char* filename);
		~Reader();

		// Reading Methods
		string readMessage();
};

//* Constructor *//
// Creates the Reader Class with a specified File Name
inline Reader::Reader(const char* filename)
{
	// Determine Reading Flags
	int open_flag = O_CREAT | O_RDONLY;

	// Open the File
	this -> file = open(filename, open_flag, 0x1C0);

	// Make sure the File Opened
	if(this -> file < 0)
	{
		printf("Reader: Unable to open File '%s'", filename);
		return;
	}
}

//* Deconstructor *//
inline Reader::~Reader()
{
	// Close the File
	close(file);
}

//* Reading Methods *//
// Reads until End of File
inline string Reader::readMessage()
{
	// Initialize the Message
	string message = "";

	while(true)
	{
		// Create the Read Buffer
		char buffer[1];

		// Read from File
		int count = read(this -> file, buffer, sizeof(char));

		// Determine whether or not new Data was Read
		if(count <= 0)
			return message;

		// Annex the new Data to the Message
		message += buffer[0];
	}
}

//* End of Header Definition *//
#endif
