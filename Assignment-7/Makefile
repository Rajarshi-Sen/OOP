# -----------------------------------------------------------
# Name       : Rajarshi Sen
# Z_Id       : z1816768
# Course     : CSCI 689
# Section    : 1
# Due Date   : April 18, 2017 by midnight
# Purpose    : to help create the executable of Assignment-7
#              and clear out the project to pristine state.
# -----------------------------------------------------------

CC = g++
CCFLAGS = -Wall -std=c++11

assign7: assign7.o container.o
	$(CC) $(CCFLAGS) -o assign7 assign7.o container.o

assign7.o: assign7.cc assign7.h
	$(CC) $(CCFLAGS) -c assign7.cc

container.o: container.cc container.h
	$(CC) $(CCFLAGS) -c container.cc

clean:
	rm *.o assign7
