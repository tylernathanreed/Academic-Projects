//* Description *//
// Title: itoa (Integer to ASCII)
// Author: Tyler Reed
// Creates the itoa function

//* Header Definition *//
#ifndef ITOA_H
#define ITOA_H

//* Namespace *//
namespace ITOA
{
	// Reverses the specified String
	inline char* reverse(char s[], int size)
	{
		int start, end;
		char c;

		// Loop from the Ends of the String to the center
		for(start = 0, end = size - 1; start < end; start++, end--) 
		{
			// Grab a Temp Char
			c = s[start];

			// Swap the Characters
			s[start] = s[end];
			s[end] = c;
		}

		return s;
	}

	// Converts the specified Integer to ASCII
	inline char* itoa(int n)
	{
		// Create the Character String
		char s[10] = {'\0'};

		bool negative = n < 0;
		int digits;

		// Check if the Number is Negative
		if(negative)
			n = -n; // Make the Number Positive

		digits = 0;
		do
		{
			// Grab the Digits in Reverse Order
			s[digits++] = n % 10 + '0';
		}
		while((n /= 10) > 0); // Remove the Right-Most Digit

		// Add the Negative Sign back in
		if(negative)
			s[digits++] = '-';

		// Terminate the String with a Null Character
		s[digits] = '\0';

		// Reverse the String
		return reverse(s, digits);
	}
}

//* End of Header Definition *//
#endif
