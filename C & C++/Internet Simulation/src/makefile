### Description ###
# Title: Makefile
# Author: Tyler Reed
# Auto-Compiles the Executable with the proper Arguments

# Compile Specification
Node: Main.cpp
	g++ ./Main.cpp ./DataLink.cpp ./Network.cpp ./Transport.cpp -o Node

# Clean Specification
clean:
	rm -rf *.o Node & rm Channels/* & rm Output/*

# Clear Specification
clear:
	rm Channels/* & rm Output/*
