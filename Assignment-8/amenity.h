/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: April 26, 2017 by midnight
 * Program : to make a class which represent Amenities
 * Purpose : to gain experience in different ways of 
 *           >manipulating Vector 
 *           >along with some additional I/O experience.
 *****************************************************************************************/

/******************************************************************************************
 * Header file for class Amenity
 * Pre-processor directives
 * It is protected with Header Guards
 *****************************************************************************************/
# ifndef AMENITY_H
# define AMENITY_H

# include<string>
# include<fstream>

using std::string;
using std::ifstream;

class Amenity
{
   /* ******************************************************
    * private data members --> Amenity
    * to hold the respective data for each county
    *******************************************************/
   int ID;
   string state;
   string county;
   float avg_temp_jan;        // field 0 -> function object
   float sunlight_jan;        // field 1 -> function object
   float avg_temp_july;       // field 2 -> function object
   float avg_humid_july;      // field 3 -> function object
   int landform;              // field 4 -> function object
   float percent_area_water;  // field 5 -> function object

   //needs to be computed
   float comp_amenity_score;  // field 6 -> function object

   // stores the total number of records read - has to be computed
   int count;
   
   /* *******************************************************
    * public variables and methods to
    * initialise an instanace of Amenity
    * perform operations of the private data
    ********************************************************/
 public:

   /* *******************************************************
    * default constructor:
    * initialises with default values
    *********************************************************/
   Amenity();

   /* **********************************************************
    * overloading the input operator ">>"
    * to take values directly from the file into Amenity
    * implementing as a friend function as to avoid the need of 
    * having setters
    ************************************************************/
   friend ifstream & operator >> (ifstream &, Amenity &);

   /* ***********************************************************
    * setter for the composite amenity score
    *************************************************************/
   void score(float f){comp_amenity_score = f;}

   /* ***********************************************************
    * accessor methods -> only getters
    * as inline methods.
    ************************************************************/

   int get_ID()const { return ID; }

   string get_state()const { return state; }

   string get_county()const { return county; }

   float get_temp_jan()const { return avg_temp_jan; }

   float get_sunlight()const { return sunlight_jan; }

   float get_temp_july()const { return avg_temp_july; }

   float get_humidity()const { return avg_humid_july; }

   int get_landform()const { return landform; }

   float get_percent()const { return percent_area_water; }

   float score()const { return comp_amenity_score; }

   int get_count()const { return count; }

};

/* **********************************************************
 * Amenity Helper Functions:
 ************************************************************/
     
/* **********************************************************
 * compares jan temp of two Amenity instances
 * returns true if LHS->avg_temp_jan > RHS->avg_temp_jan
 ************************************************************/
bool compare_temp_jan(const Amenity &, const Amenity &);

/* ***********************************************************
 * comapares jan sunlight of two Amenity instances
 * returns true if LHS->sunlight_jan > RHS->sunlight_jan
 ************************************************************/
bool compare_sun_jan(const Amenity &, const Amenity &);

/* **********************************************************
 * compares july temperatue of two Amenity instances
 * returns true if LHS->avg_temp_july < RHS-avg_temp_july
 ************************************************************/
bool compare_temp_july(const Amenity &, const Amenity &);

/* ************************************************************
 * compares July humidity of two Amenity instances
 * returns true if LHS->avg_humid_july < RHS->avg_humid_july
 **************************************************************/
bool compare_humid_july(const Amenity &, const Amenity &);

/* ************************************************************
 * compares the landform of two Amenity instances
 * returns true if LHS->landform > RHS->landform
 **************************************************************/
bool comapre_landform(const Amenity &, const Amenity &);

/* ******************************************************************
 * compares percent_area_water of two Amenity instances
 * returns true if LHS->percent_area_water > RHS->percent_area_water
 ********************************************************************/
bool compare_water(const Amenity &, const Amenity &);

# endif /* end of AMENITY_H */
