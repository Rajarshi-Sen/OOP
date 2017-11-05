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

/* ****************************************************************************************
 * Implementation file for class Person and helper functions
 *****************************************************************************************/

# include "person.h"

/* ***********************************************************************************
 * for splitting up the date and place
 ************************************************************************************/
void parse(const string & in, string & s1, string & s2, string & s3);

/* ****************************************************************
 * default constructor:
 * initiializes father, mother and child to -1
 * all others are initialized using their default constructors
 ******************************************************************/
Person::Person()
{
    father = -1;
    mother = -1;
    child  = -1;
}

/* ***************************************************************
 * parmeterized constructor that takes values for all
 * internal data members and sets them accordingly.
 *****************************************************************/
Person::Person(string const & name1, string const & name2, string const & b_d, string const & b_p, string const & d_d, string const & d_p, int const f, int const m, int const c)//:l_name(name1), f_name(name2), b_place(b_p), d_place(d_p), father(f), mother(m), child(c)
{
    string s1, s2, s3;
    l_name = Name(name1);
    f_name = Name(name2);
    
    parse(b_d, s1, s2, s3);
    b_date = Date(s1, s2, s3);

    parse(b_p, s1, s2, s3);
    b_place = {s1, s2, s3};
    
    parse(d_d, s1, s2, s3);
    d_date = Date(s1, s2, s3);

    parse(d_p, s1, s2, s3);
    d_place = {s1, s2, s3};

    father = f;
    mother = m;
    child = c;
}

void parse(const string & in, string & s1, string & s2, string & s3)
{
    const char delim = '#';
    stringstream in_stream(in);
    getline(in_stream, s1, delim);
    getline(in_stream, s2, delim);
    getline(in_stream, s3, delim);
}

/* ***************************************************************
 * returns position of father
 ****************************************************************/
int Person::get_father()const
{
    return father;
}

/* ***************************************************************
 * returns position of mother
 ****************************************************************/
int Person::get_mother()const
{
    return mother;
}

/* ***************************************************************
 * returns position of child
 ****************************************************************/
int Person::get_child()const
{
    return child;
}

/* **************************************************************
 * @arg -> refernce to textCanvas ************ REMAINING
 * displays the instance's information as required.
 ****************************************************************/
void Person::print(textCanvas & tc)const
{
    tc.print_char('\n');
    l_name.print(tc);
    tc.print_char(',');
    tc.print_char(' ');
    f_name.print(tc);
    if(tc.print_char('\n')==TC_CURSOR_OUT_OF_BOX)
    {
	tc.row++;
	tc.col = tc.left;
    }
    tc.print_string("b. ");
    b_date.print(tc);
    if(tc.print_char('\n')==TC_CURSOR_OUT_OF_BOX)
    {
	tc.row++;
	tc.col = tc.left;
    }
    tc.print_string("   ");
    b_place.print(tc);
    if(tc.print_char('\n')==TC_CURSOR_OUT_OF_BOX)
    {
	tc.row++;
	tc.col = tc.left;
    }
    tc.print_string("d. ");
    d_date.print(tc);
    if(tc.print_char('\n')==TC_CURSOR_OUT_OF_BOX)
    {
	tc.row++;
	tc.col = tc.left;
    }
    tc.print_string("   ");
    d_place.print(tc);
    if(tc.print_char('\n')==TC_CURSOR_OUT_OF_BOX)
    {
	tc.row++;
	tc.col = tc.left;
    }
    //cout<<endl;
  //  cout<< father<<mother<<child<<endl;
}
  

      
   
