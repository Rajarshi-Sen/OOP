/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: April 18, 2017 by midnight
 * Program : to read a file into set and display them.
 * Purpose : to gain experience with STL set and operator overloading.
 *****************************************************************************************/

/******************************************************************************************
 * Header file for class Assign7
 * Pre-processor directives
 * It is protected with Header Guards
 *****************************************************************************************/
#ifndef ASSIGN_7_H
#define ASSIGN_7_H

#include "container.h"
#include <fstream>
#include <set>

using std::ifstream;
using std::set;

class Assign7
{
   /* ***************************************
    * private members:
    ****************************************/
   ifstream fin;
   set<Container> s_cont;
   Container ref_c;
   
   /* *******************************************
    * public members
    ********************************************/
 public:

   /* ********************************************************************
    * Default Constructor
    **********************************************************************/
   Assign7(){ s_cont.clear(); }
   
   /* ********************************************************************
    * explains how to use the class propely
    * cannot be const method (checked)
    *********************************************************************/
   void usage()const;

   /* ********************************************************************
    * to open the file:
    * @file_name: is the file name passed via command line argument
    * returns true when file is opened otherwise false.
    *********************************************************************/
   bool open_file(const string& file_name);
   
   /* *******************************************************************
    * reads from the input file
    * reads in characters for simplicity
    * also puts them into the set via Container class
    *********************************************************************/
   void read_file();

   /* *******************************************************************
    * prints the element of the set
    *********************************************************************/
   void print_set();

};

#endif /* end of ASSIGN_7_H */
