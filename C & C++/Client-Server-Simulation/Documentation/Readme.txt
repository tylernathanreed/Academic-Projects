Project 3: Readme.txt

In order to compile to program, you may either run the existing 'Project3' executable,
or use the 'make clean' then 'make' command to recompile.

Once compiled, you can run the Server with the following command:
	Project3 -s <port> (Ex: Project3 -s 1234)

The Client may be run similarly:
	Project3 -c <host> <port> (Ex: Project3 -c cs1 1234)

It should be noted that both the Server and Client may run with optional debug tags along
with a debug level. This isn't neccesary for grading, but it might help you fully understand
what's going on in the background.

Either process may be run in debug mode with the optional '-d' tag followed by a debug
level (0-3), where 0 is off, and 3 is the highest implemented debug level. The higher you
go, the more details you will see.

Here are some examples for running in debug mode:
	Server Example: Project3 -s 1100 -d 3
	Client Example: Project3 -c cs1 1100 -d 3