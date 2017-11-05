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
 * Header file for class Person
 * Pre-processor directives
 * It is protected with Header Guards
 *****************************************************************************************/

# ifndef PERSON_H
# define PERSON_H

# include <sstream>
# include "name.h"
# include "date.h"
# include "place.h"
# include "textCanvas.h"

using std::endl;
using std::stringstream;

class Person
{
    Name l_name;
    Name f_name;
    Date b_date;
    Place b_place;
    Date d_date;
    Place d_place;
    /* ************************************************************
     * position of the relatives in the vector:
     *************************************************************/
    int father;
    int mother;
    int child;

 public:

    /* ****************************************************************
     * default constructor:
     * initiializes father, mother and child to -1
     * all others are initialized using their default constructors
     ******************************************************************/
    Person();

    /* ***************************************************************
     * parmeterized constructor that takes values for all
     * internal data members and sets them accordingly.
     *****************************************************************/
    Person(string const & name1, string const & name2,
	   string const & b_d, string const & b_p,
	   string const & d_d, string const & d_p,
	   const int f, const int m, const int c);

    /* ***************************************************************
     * returns position of father
     ****************************************************************/
    int get_father()const;

    /* ***************************************************************
     * returns position of mother
     ****************************************************************/
    int get_mother()const;

    /* ***************************************************************
     * returns position of child
     ****************************************************************/
    int get_child()const;

    /* **************************************************************
     * @arg -> refernce to textCanvas
     * displays the instance's information as required.
     ****************************************************************/
    void print(textCanvas & tc)const;
};

# endif /* End of PERSON_H */
