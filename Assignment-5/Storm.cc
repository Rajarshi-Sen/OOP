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
 * Pre-processor directives
 ******************************************************************************************/
# include "Storm.h"

/******************************************************************************************
 * to retreive the value of data member storm_type
 * also promises not to change the instance member values
 ******************************************************************************************/
char Storm::get_storm_type()const{ return storm_type; }

/******************************************************************************************
 * to retreive the value of data member sequence
 * also promises not to change the instance member values
 ******************************************************************************************/
int  Storm::get_sequence()const{ return sequence; }

/******************************************************************************************
 * to retreive the value of data member year
 * also promises not to change the instance member values
 ******************************************************************************************/
int  Storm::get_year()const{ return year; }

/******************************************************************************************
 * to retreive the value of data member max_wind_speed
 * also promises not to change the instance member values
 ******************************************************************************************/
int  Storm::get_max_wind_speed()const{ return max_wind_speed; }

/******************************************************************************************
 * to retreive the value of data member min_air_press
 * also promises not to change the instance member values
 ******************************************************************************************/
int  Storm::get_min_air_press ()const{ return min_air_press; }

/******************************************************************************************
 * to print the data member values of the instance
 * takes care of the field output formatting
 * also promises not to change the instance member values
 ******************************************************************************************/
void Storm::print() const
{
    const int field_width = 35;
    const int field_width2 = 15;
    const int field_width3 = 10;
    switch(ocean_basin)
    {
      case 'A':
	cout<< left << setw(field_width) << " Atlantic Ocean";
	break;
      case 'E':
	cout<< left << setw(field_width) << " northeastern Pacific Ocean";
	break;
      case 'C':
	cout<< left << setw(field_width) << " central Pacific Ocean";
	break;
      default:
	cout<< setw(field_width) << " ";
	break;
    }
    switch(storm_type)
    {
        case 'H':
	  cout<< setw(field_width2) << "Hurricane";
	  break;
        case 'S':
	  cout<< setw(field_width2) << "Storm";
	  break;
        case 'D':
	  cout<< setw(field_width2) << "Depression";
	  break;
        default:
	  cout<< setw(field_width2) << " ";
	  break;
    }
    if (!(storm_name == "None"))
       cout<< setw(field_width3) << storm_name;
    else
       cout<< setw(field_width3) << "UNNAMED";
    cout<< right << setw(field_width3) << sequence << "/" << year;
    if (max_wind_speed != -1)
       cout<< setw(field_width3) << max_wind_speed;
    else
       cout<< setw(field_width3) << " ";
    if (min_air_press != 10000)
       cout<< setw(field_width3) << min_air_press;
    else
       cout<< setw(field_width3) << " ";
    cout<< left << endl;

    return;
}
