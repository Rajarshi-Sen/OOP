# -----------------------------------------------------------
# Name       : Rajarshi Sen
# Z_Id       : z1816768
# Course     : CSCI 689
# Section    : 1
# Due Date   : April 7, 2017 by midnight
# Purpose    : to help create the executable of Assignment-6
#              and clear out the project to pristine state.
# -----------------------------------------------------------

CC = g++
CCFLAGS = -Wall -std=c++11

assign6: assign6.o person.o name.o date.o place.o textCanvas.o
	$(CC) $(CCFLAGS) -o assign6 assign6.o person.o name.o date.o place.o textCanvas.o

assign6.o: assign6.cc
	$(CC) $(CCFLAGS) -c assign6.cc

person.o: person.cc person.h
	$(CC) $(CCFLAGS) -c person.cc

name.o: name.cc name.h
	$(CC) $(CCFLAGS) -c name.cc

date.o: date.cc date.h
	$(CC) $(CCFLAGS) -c date.cc

place.o: place.cc place.h
	$(CC) $(CCFLAGS) -c place.cc

textCanvas.o: textCanvas.cc textCanvas.h
	$(CC) $(CCFLAGS) -c textCanvas.cc

clean:
	rm *.o assign6

# END OF MAKEFILE
