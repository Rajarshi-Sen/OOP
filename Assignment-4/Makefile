# -----------------------------------------------------------
# Name       : Rajarshi Sen
# Z_Id       : z1816768
# Course     : CSCI 689
# Section    : 1
# Due Date   : February 27, 2017 by midnight
# Purpose    : to help create the executable of Assignment-4
#              and clear out the project to pristine state.
# -----------------------------------------------------------

CC = g++
CCFLAGS = -Wall -std=c++11
assign4: processFile.o process_data.o
	$(CC) $(CCFLAGS) -o assign4 processFile.o process_data.o
processFile.o: processFile.cc processFile.h
	$(CC) $(CCFLAGS) -c processFile.cc
process_data.o: process_data.cc processFile.h
	$(CC) $(CCFLAGS) -c process_data.cc
clean:
	rm *.o assign4
