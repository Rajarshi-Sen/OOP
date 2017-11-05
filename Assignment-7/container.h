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
 * Header file for class Container
 * Pre-processor directives
 * It is protected with Header Guards
 *****************************************************************************************/
#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Container
{
   /* ************************************************************
    * private data members
    *************************************************************/
   int key;
   string value;

   /* ************************************************************
    * public members
    *************************************************************/
  public:

   /* ****************************************************************************
    * parameterised constructor with default argument values:
    * takes care of both-
    * default value initialisation, and
    * proper initialisation with passed in values using initialisation list
    ******************************************************************************/
   Container(int key = 0, string value = "");

   /* ****************************************************************************
    * overloading the subscript operator "[]"
    * to provide access to the string data member only
    *****************************************************************************/
   string operator [](const int index)const { return value; }

   /* ****************************************************************************
    * overloading the less than operator "<"
    * to provide STL set with a means of comparing between two Container instances
    ******************************************************************************/
   bool operator <(const Container & rhs)const;

};

/* *****************************************************************************************
 * overloadimg the output operator "<<"
 * to print the string data member of the class to the output stream
 * declaring the function prototype in the header file for proper communication
 * doing it as a function:
 * > Container class has to be the rhs
 * > not using friend as do not want to provide direct access to the private data members.
 * returning a refernce to output stream "ostream" to enable chaining
 ********************************************************************************************/
ostream& operator <<(ostream& ostr, const Container & ref_c);


#endif /* end of CONTAINER_H */
