//* Description *//
// Title: Hex to Byte (and Byte to Hex)
// Author: Tyler Reed
// Converts a Hexadecimal Value to a Byte Character (supports reverse operation)

//* Header Definition *//
#ifndef HTOB_H
#define HTOB_H

//* Namespace *//
// Converts Hexadecimal to Byte Characters
namespace HTOB
{
	// Hex Values
	static const char* HEX_VALUES = "0123456789ABCDEF";

	// Converts the Low Hex Character to Byte
	static char low(const char &value)
	{
		if('0' <= value && value <= '9')
			return (char) (value - '0');
		else if('A' <= value && value <= 'F')
			return (char) (10 + (value - 'A'));
	}

	// Converts the High Hex Character to Byte
	static char high(const char &value)
	{
		return low(value) << 4;
	}

	// Converts Hexadecimal to Decimal (Char)
	static char htob(const char hi, const char lo)
	{
		return high(hi) | low(lo);
	}

	// Converts Bytes to a Hex String
	static const char* btoh(const char byte)
	{
		char hex[3] = {'\0'};

		hex[0] = HEX_VALUES[((byte >> 4) & 0xF)];
		hex[1] = HEX_VALUES[(byte) & 0x0F];

		char* p = hex;
		return p;
	}
}

//* End of Header Definition *//
#endif
