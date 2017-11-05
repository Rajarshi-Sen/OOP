# -----------------------------------------------------------
# Name       : Rajarshi Sen
# Z_Id       : z1816768
# Course     : CSCI 689
# Section    : 1
# Due Date   : February 8, 2017 by midnight
# Purpose    : to help create the executable of Assignment-2
#              and clear out the project to pristine state.
# -----------------------------------------------------------

CC = g++
CCFLAGS = -Wall

assign2 : assign2.o functions.o
	$(CC) $(CCFLAGS) -o assign2 assign2.o functions.o
assign2.o : assign2.cc functions.h
	$(CC) $(CCFLAGS) -c assign2.cc
functions.o : functions.cc functions.h
	$(CC) $(CCFLAGS) -c functions.cc
clean:
	rm *.o assign2
