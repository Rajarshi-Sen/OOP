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

/******************************************************************************************
 * Header file for class Date
 * Pre-processor directives
 * It is protected with Header Guards
 *****************************************************************************************/
# ifndef DATE_H
# define DATE_H

# include "textCanvas.h"

class Date
{
    string day;
    string month;
    string year;

 public:

    /* *********************************************************************************************
     * Default Constructor: initializes each of the member string with a null terminating character
     **********************************************************************************************/
    Date();

    /* *********************************************************************************************
     * Parameterized COnstructor: initializes the data members with three string values.
     **********************************************************************************************/
    Date(const string & d, const string & m, const string & y);

    /* *******************************************************************************
     * @arg -> refernce to textCanvas 
     * prints out the data member to the textCanvas
     ********************************************************************************/
    void print(textCanvas & tc)const;
};

# endif /* End  of DATE_H */
