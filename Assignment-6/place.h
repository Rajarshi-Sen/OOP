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
 * Header file for class Place
 * Pre-processor directives
 * It is protected with Header Guards
 *****************************************************************************************/
# ifndef PLACE_H
# define PLACE_H

# include "name.h"
# include "textCanvas.h"

class Place
{
    Name city;
    Name county;
    Name state;

 public:

    /* *************************************************************************************
     * Default Constructor: initializes the internal strings with default values properly.
     *************************************************************************************/
    Place();

    /* **************************************************************************************
     * Paremeterized Constructor: initializes the data memebers properly.
     ***************************************************************************************/
    Place(const string &, const string &, const string &);

    /* *******************************************************************************
     * @arg -> refernce to textCanvas
     * prints out the data member to the textCanvas
     ********************************************************************************/
    void print(textCanvas & tc)const;

};

# endif /* End of PLACE_H */
  
