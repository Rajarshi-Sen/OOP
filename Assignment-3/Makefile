# -----------------------------------------------------------
# Name       : Rajarshi Sen
# Z_Id       : z1816768
# Course     : CSCI 689
# Section    : 1
# Due Date   : February 17, 2017 by midnight
# Purpose    : to help create the executable of Assignment-3
#              and clear out the project to pristine state.
# -----------------------------------------------------------

CC = g++
CCFLAGS = -Wall -std=c++11
allExec: generate thresh
generate: generate.o inputParseFunctions.o fileHandlingFunctions.o
	$(CC) $(CCFLAGS)  -o generate generate.o inputParseFunctions.o fileHandlingFunctions.o
thresh: thresh.o inputParseFunctions.o fileHandlingFunctions.o
	$(CC) $(CCFLAGS)  -o thresh thresh.o inputParseFunctions.o fileHandlingFunctions.o
generate.o: generate.cc assign3HelperFunctions.h
	$(CC) $(CCFLAGS)  -c generate.cc
thresh.o: thresh.cc assign3HelperFunctions.h
	$(CC) $(CCFLAGS)  -c thresh.cc
inputParseFunctions.o: inputParseFunctions.cc assign3HelperFunctions.h
	$(CC) $(CCFLAGS)  -c inputParseFunctions.cc
fileHandlingFunctions.o: fileHandlingFunctions.cc assign3HelperFunctions.h
	$(CC) $(CCFLAGS)  -c fileHandlingFunctions.cc
clean:
	rm *.o generate thresh
