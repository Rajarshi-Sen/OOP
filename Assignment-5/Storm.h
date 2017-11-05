
/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: March 10, 2017 by midnight
 * Program : to generate report from a collection of data.
 * Purpose : to gain experience in:
 *         : writing simple classes, using C++ vectors, and writing multi-part programs.
 *****************************************************************************************/
/******************************************************************************************
 * Header file
 * Pre-processor directives
 * It is protected with Header Guards
 *****************************************************************************************/
# ifndef STORM_H
# define STORM_H

# include <iostream>
# include <fstream>
# include <iomanip>
# include <vector>

using std::cout;
using std::cin;
using std::cerr;
using std::ifstream;
using std::setw;
using std::string;
using std::vector;
using std::right;
using std::fixed;
using std::endl;
using std::left;

class Storm
{
    char ocean_basin;
    char storm_type;
    int  sequence;
    int  year;
    int  min_air_press;
    int  max_wind_speed;
    string storm_name;

 public:
/******************************************************************************************
 * this is the constructor with parameters, default argument, and initializer list
 * so it functions as
 * > the default constructor
 * > the parameterized constructor
 ******************************************************************************************/
 Storm(const char b = 'N', const char t = 'N', const int s = 0, const int y = 0, const int a_p = 0, const int w_s = 0, const string & n = "None"):
    ocean_basin(b), storm_type(t), sequence(s), year(y), min_air_press(a_p), max_wind_speed(w_s), storm_name(n){ }

/******************************************************************************************
 * to print the data member values of the instance
 * takes care of the field output formatting
 * also promises not to change the instance member values
 ******************************************************************************************/
    void print() const;
	
/******************************************************************************************
 * to retreive the value of data member storm_type
 * also promises not to change the instance member values
 ******************************************************************************************/
    char get_storm_type()const;
	
/******************************************************************************************
 * to retreive the value of data member sequence
 * also promises not to change the instance member values
 ******************************************************************************************/
    int  get_sequence()const;
	
/******************************************************************************************
 * to retreive the value of data member year
 * also promises not to change the instance member values
 ******************************************************************************************/
    int  get_year()const;
	
/******************************************************************************************
 * to retreive the value of data member max_wind_speed
 * also promises not to change the instance member values
 ******************************************************************************************/
    int  get_max_wind_speed()const;
	
/******************************************************************************************
 * to retreive the value of data member min_air_press
 * also promises not to change the instance member values
 ******************************************************************************************/
    int  get_min_air_press ()const;
};
# endif /*** end of STORM_H ***/
