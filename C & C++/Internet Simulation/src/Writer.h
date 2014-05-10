//* Description *//
// Title: Writer
// Author: Tyler Reed
// Prompts User for Input and Writes to File

//* Header Definition *//
#ifndef H_WRITER
#define H_WRITER

//* Libraries *//
#include <stdio.h>
#include <fcntl.h>
#include <string>

//* Namespaces *//
using namespace std;

//* Writer Class *//
class Writer
{
	//* Class Variables *//
	// Private Variables
	private:
		int file;

	//* Class Methods *//
	// Public Methods
	public:
		// Constructor and Deconstructor
		Writer(const char* filename);
		~Writer();

		// Writing Methods
		void writeMessage(string data);
};

//* Constructor *//
// Creates the Writer Class with a specified File Name
inline Writer::Writer(const char* filename)
{
	// Determine the Opening Flags
	int open_flag = O_TRUNC | O_CREAT | O_WRONLY;

	// Open the File
	this -> file = open(filename, open_flag, 0x1C0);

	// Make sure the File Opened
	if(file < 0)
	{
		printf("Writer: Unable to open File '%s'", filename);
		return;
	}
}

//* Deconstructor *//
inline Writer::~Writer()
{
	// Close the File
	close(file);
}

//* Writing Methods *//
// Writes the specified String to File
inline void Writer::writeMessage(string message)
{
	// Write to File
	write(this -> file, message.c_str(), message.length());
}

//* End of Header Definition *//
#endif
