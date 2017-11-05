# -----------------------------------------------------------
# Name       : Rajarshi Sen
# Z_Id       : z1816768
# Course     : CSCI 689
# Section    : 1
# Due Date   : March 10, 2017 by midnight
# Purpose    : to help create the executable of Assignment-4
#              and clear out the project to pristine state.
# -----------------------------------------------------------

CC = g++
CCFLAGS = -Wall -std=c++11

all: assign5Main.o assign5.o storm.o assign5.h Storm.h
	$(CC) $(CCFLAGS) -o assign5 assign5Main.o assign5.o Storm.o

assign5Main.o: assign5Main.cc assign5.o storm.o
	$(CC) $(CCFLAGS) -c assign5Main.cc

assign5.o: assign5.cc storm.o assign5.h
	$(CC) $(CCFLAGS) -c assign5.cc

storm.o: Storm.cc Storm.h
	$(CC) $(CCFLAGS) -c Storm.cc

clean:
	rm *.o assign5
