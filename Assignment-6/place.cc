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
 * Implementation file for class Place methods
 ***************************************************************************************/
# include "place.h"

/* *************************************************************************************
 * Default Constructor: initializes the internal strings with default values properly.
 *************************************************************************************/
Place::Place()
{
    city = Name();
    county = Name();
    state = Name();
}

/* **************************************************************************************
 * Paremeterized Constructor: initializes the data memebers properly.
 ***************************************************************************************/
Place::Place(const string & c, const string & co, const string & s):city(c), county(co), state(s){}  

/* *******************************************************************************
 * @arg -> refernce to textCanvas
 * prints out the data member to the textCanvas
 ********************************************************************************/
void Place::print(textCanvas & tc)const
{
    city.print(tc);
    tc.print_char(',');
    tc.print_char(' ');
    county.print(tc);
    tc.print_char(',');
    tc.print_char(' ');
    state.print(tc);
}
