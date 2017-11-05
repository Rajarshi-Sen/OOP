/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: April 26, 2017 by midnight
 * Program : to create the Helper class for sorting and printing of Amenitys
 * Purpose : to gain experience:
 *           >Function Objects.
 *           >helps in selective printing of an Amenity
 *           >also used to compare two different Amenitys
 *****************************************************************************************/

/******************************************************************************************
 * Header file for class Sort_Print
 * Pre-processor directives
 * It is protected with Header Guards
 *****************************************************************************************/

# ifndef SORT_PRINT_H
# define SORT_PRINT_H

# include <iostream>
# include <iomanip>
# include "amenity.h"
# include <vector>
# include <algorithm>

using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;
using std::setprecision;
using std::vector;

class Sort_Print
{
   /* ********************************************
    * private data member
    * should be set with an integer indicating
    * one of the data fields of Amenity
    **********************************************/
  int attribute;

  /* *********************************************
   * private constructor
   * as there are no good default values
   ***********************************************/
  Sort_Print(){}

 public:
  /* *******************************************************
   * parameterised constructor
   ********************************************************/
  Sort_Print(int a):attribute(a){}

  /* ******************************************************************************
   * overlaoding the function operator
   * @arg: Amenity
   * returns nothing
   * prints out the selected contents of the Amenity as required
   *******************************************************************************/
  void operator ()(const Amenity &)const;

  /* *****************************************************************************
   * overloading the function operator
   * compares two Amenitys and returns bool
   * uses the value of attribute to decide the field/which function to be used
   *******************************************************************************/
  bool operator ()(const Amenity &, const Amenity &)const;

};

/* ******************************************************************
 * strongly associated function
 * @arg: vector<Amenity>, integer N, Sort_Print
 * prints out the vector using the helper class instance 
 * to print each individual row
 * for first and last N elements
 * along with elipsis(...) separating the two sections
 **********************************************************************/
void print_top_bottom_n(const vector<Amenity> &, const int, const Sort_Print & sp);

# endif /* end of SORT_PRINT_H */
