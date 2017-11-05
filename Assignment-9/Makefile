# -----------------------------------------------------------
# Name       : Rajarshi Sen
# Z_Id       : z1816768
# Course     : CSCI 689
# Section    : 1
# Due Date   : May 4, 2017 by midnight
# Purpose    : to help create the executable of Assignment-9
#              and clear out the project to pristine state.
# -----------------------------------------------------------

CC = g++
CCFLAGS = -Wall -std=c++11

vectortest: vectortest.o
	$(CC) $(CCFLAGS) -o vectortest vectortest.cc

vectortest.o: vectortest.cc vectorN.h
	$(CC) $(CCFLAGS) -c vectortest.cc

clean:
	rm *.o vectortest
