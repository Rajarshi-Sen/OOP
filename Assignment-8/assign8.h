/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: April 26, 2017 by midnight
 * Program : to make the main class for assignment 8
 * Purpose : to gain experience in different ways of
 *           >manipulating Vector
 *           >along with some additional I/O experience.
 *****************************************************************************************/

/******************************************************************************************
 * Header file for class assign8
 * Pre-processor directives
 * It is protected with Header Guards
 *****************************************************************************************/
# ifndef ASSIGN_8_H
# define ASSIGN_8_H

/* *********************************************************************************
 * reads the data from a file --> amenity.dat
 * into a vector of Amenities via an input function
 * also has a Composite Amenity Function; which computes and stores
 * the composite value for each
 ***********************************************************************************/
# include "amenity.h"
# include <vector>
# include <iostream>
# include <algorithm>
# include "math_vector.h"
# include "sort_print.h"

using std::vector;
using std::cout;
using std::endl;
using std::for_each;

class Assign8
{
   /* ************************************************************
    * private data members
    *************************************************************/
   ifstream fin;
   vector<Amenity> amenities;
   Amenity amenity;
  
   /* *************************************************************
    * public methods:
    ***************************************************************/
  public:
   
   /* ********************************************************************
    * Default Constructor
    **********************************************************************/
   Assign8(){ amenities.reserve(3073); }

   /* ********************************************************************
    * Destructor
    *********************************************************************/
   ~Assign8(){ amenities.clear(); }
   
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
    * puts them into the vector of Amenitys
    *********************************************************************/
   void input();

   /* ******************************************************************
    * prints the number of records read
    * or the total number of Amenities
    ********************************************************************/
   void print_count()const { cout<< " "<< amenity.get_count()<< " records input. "<<endl; }

   /* ***************************************************************************
    * computes and stores the composite amenity value for each one
    * depends on knowing the average and standard deviation of the 
    * individual amenities over all instances
    * **************************************************************************/
   void calc_composite();
   
   /* *******************************************************************
    * prints the element of the vector
    * using the helper class Sort_Print
    * the closely associated function: print_top_bottom_n
    * sort via function pointers or function objects
    *********************************************************************/
   void print();

};

# endif /* end of ASSIGN_8_H */
