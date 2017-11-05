/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: April 26, 2017 by midnight
 * Program : to create the Helper class for sorting and printing of Amenitys
 * Purpose : to gain experience:
 *           >Function Objects.
 *           >helps in selective printing of an Amenity
 *           >also used to compare two different Amenitys
 *****************************************************************************************/

/* *************************************************************************************
 * implementation file for class Sort_Print
 ***************************************************************************************/
# include "sort_print.h"

/* ******************************************************************************
 * overlaoding the function operator
 * @arg: Amenity
 * returns nothing
 * prints out the selected contents of the Amenity as required
 * default justification is right
 *******************************************************************************/
void Sort_Print::operator ()(const Amenity & amenity)const
{
   const int FIELD_WIDTH = 15;
   cout<< setw(FIELD_WIDTH)<< amenity.get_county();
   cout<< "   ";
   cout<< setw(FIELD_WIDTH)<< left<< amenity.get_state();
   switch(attribute)
   {
     case 0:
       cout<< setprecision(3)<< setw(FIELD_WIDTH)<< right<< amenity.get_temp_jan();
       break;
     case 1:
       cout<< setprecision(4)<< setw(FIELD_WIDTH)<< right<< amenity.get_sunlight();
       break;
     case 2:
       cout<< setprecision(3)<< setw(FIELD_WIDTH)<< right<< amenity.get_temp_july();
       break;
     case 3:
       cout<< setw(FIELD_WIDTH)<< right<< amenity.get_humidity();
       break;
     case 4:
       cout<< setw(FIELD_WIDTH)<< right<< amenity.get_landform();
       break;
     case 5:
       cout<< setprecision(6)<< setw(FIELD_WIDTH)<< right<< amenity.get_percent();
       break;
     case 6:
       cout<< setprecision(6)<< setw(FIELD_WIDTH)<< right<< amenity.score();
       break;
   }
   cout<< endl;
}

/* *****************************************************************************
 * overloading the function operator
 * compares two Amenitys and returns bool
 * uses the value of attribute to decide the field/which function to be used
 *******************************************************************************/
bool Sort_Print::operator ()(const Amenity & lhs, const Amenity & rhs)const
{
   switch(attribute)
   {
     case 0:
       return compare_temp_jan(lhs, rhs);
       break;
     case 1:
       return compare_sun_jan(lhs, rhs);
       break;
     case 2:
       return compare_temp_july(lhs, rhs);
       break;
     case 3:
       return compare_humid_july(lhs, rhs);
       break;
     case 4:
       return comapre_landform(lhs, rhs);
       break;
     case 5:
       return compare_water(lhs, rhs);
       break;
     case 6:
       return (lhs.score() > rhs.score());
       break;
   }
   return true;
}

/* ******************************************************************
 * strongly associated function
 * @arg: vector<Amenity>, integer N, Sort_Print
 * prints out the vector using the helper class instance
 * to print each individual row
 * for first and last N elements
 * along with elipsis(...) separating the two sections
 **********************************************************************/
void print_top_bottom_n(const vector<Amenity> & v, const int n_rows, const Sort_Print & sp)
{
   const string elipsis = "  ...";
   for_each(v.begin(), v.begin()+n_rows, sp);
   cout<< elipsis<< endl;
   for_each(v.end()-n_rows, v.end(), sp);       
}
