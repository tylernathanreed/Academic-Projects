//* Description *//
// Title: Output
// Author: Tyler Reed
// Outputs the specified String to the specified File

//* Package *//
package Assignment;

//* Libraries *//
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

//* Class *//
public class Output
{
	//* Constructor *//
	// Creates the Output Class
	public Output(String filepath, String output) throws IOException
	{
		// Create the Buffered Writer
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File(filepath)));

		writer.write(output);
		writer.close();
	}
}
