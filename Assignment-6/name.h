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
 * Header file for class Name
 * Pre-processor directives
 * It is protected with Header Guards
 *****************************************************************************************/

# ifndef NAME_H
# define NAME_H

# include "textCanvas.h"

class Name
{
    string name;

 public:

    /* *********************************************************************************
     * Default Constructor: initializes the member string to empty string.
     **********************************************************************************/
    Name();

    /* ********************************************************************************
     * Parameterized Constructor: initializes the data member
     * @arg: string
     *********************************************************************************/
    Name(const string & name);

    /* *******************************************************************************
     * @arg -> refernce to textCanvas 
     * prints out the data member to the textCanvas
     ********************************************************************************/
    void print(textCanvas & tc)const;
};

# endif /* End of NAME_H */
