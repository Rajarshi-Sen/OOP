/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: April 7, 2017 by midnight
 * Program : to display a small genealogical database.
 * Purpose : to gain experience in:
 *         : writing simple classes, using C++ vectors, and writing multi-part programs.
 *****************************************************************************************/

/* **************************************************************************************
 * Implementation file for methods in class Name
 ***************************************************************************************/
# include "name.h"

/* *********************************************************************************
 * Default Constructor: initializes the member string to empty string.
 **********************************************************************************/
Name::Name()
{
    name = "";
}

/* ********************************************************************************
 * Parameterized Constructor: initializes the data member
 * @arg: string
 *********************************************************************************/
Name::Name(const string & read_name)
{
    name = read_name;
}

/* *******************************************************************************
 * @arg -> refernce to textCanvas
 * prints out the data member to the textCanvas
 ********************************************************************************/
void Name::print(textCanvas & tc)const
{
    tc.print_string(name);
}
