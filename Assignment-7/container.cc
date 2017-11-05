/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: April 18, 2017 by midnight
 * Program : to read a file into set and display them.
 * Purpose : to gain experience with STL set and operator overloading.
 *****************************************************************************************/

/* *******************************************************************************
 * implementation file for the methods in class Container
 ********************************************************************************/
#include "container.h"

/* *******************************************************************************
 * implementing the only constructor in class Container
 * takes care of all initialisations properly
 * only means to assign values to the private data members for this class
 ********************************************************************************/
Container::Container(int k, string v)
{
   key = k;
   value = v;
}

/* ****************************************************************************
 * overloading the less than operator "<"
 * to provide STL set with a means of comparing between two Container instances
 ******************************************************************************/
bool Container::operator <(Container const & rhs)const
{
   return (this->key < rhs.key);
}

/* ***************************************************************************
 * overloadimg the output operator "<<"
 * to print the string data member of the class to the output stream
 * returning a refernce to output stream "ostream" to enable chaining
 ****************************************************************************/
ostream& operator <<(ostream& ostr, const Container & ref_c)
{
   ostr<< ref_c[0];
   return ostr;
}
     
