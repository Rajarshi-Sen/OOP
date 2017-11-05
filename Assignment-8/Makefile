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

assign8: assign8.o amenity.o math_vector.o sort_print.o
	$(CC) $(CCFLAGS) -o assign8 assign8.o amenity.o math_vector.o sort_print.o

assign8.o: assign8.cc assign8.h amenity.h math_vector.h
	$(CC) $(CCFLAGS) -c assign8.cc

amenity.o: amenity.cc amenity.h
	$(CC) $(CCFLAGS) -c amenity.cc

math_vector.o: math_vector.cc math_vector.h
	$(CC) $(CCFLAGS) -c math_vector.cc

sort_print.o: sort_print.cc sort_print.h amenity.h
	$(CC) $(CCFLAGS) -c sort_print.cc

clean:
	rm *.o assign8

