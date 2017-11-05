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
 * Implementation file for methods in class Date
 ***************************************************************************************/
# include "date.h"

/* *********************************************************************************************
 * Default Constructor: initializes each of the member string with a null terminating character
 **********************************************************************************************/
Date::Date()
{
    day   = "\0";
    month = "\0";
    year  = "\0";
}

/* *********************************************************************************************
 * Parameterized COnstructor: initializes the data members with three string values.
 **********************************************************************************************/
Date::Date(const string & d, const string & m, const string & y)
{
    day = d;
    month = m;
    year = y;
}

/* *******************************************************************************
 * @arg -> refernce to textCanvas 
 * prints out the data member to the textCanvas
 ********************************************************************************/
void Date::print(textCanvas & tc)const
{
    tc.print_string(day);
    tc.print_char(' ');
    tc.print_string(month);
    tc.print_char(',');
    tc.print_char(' ');
    tc.print_string(year);
}
