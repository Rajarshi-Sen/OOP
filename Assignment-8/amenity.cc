/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: April 26, 2017 by midnight
 * Program : to implement the methods and helper functions of class Amenity
 * Purpose : to gain experience in different ways of
 *           >manipulating Vector
 *           >along with some additional I/O experience.
 *****************************************************************************************/

/* *******************************************************************************
 * implementation file for the methods and helper function of class Amenity
 ********************************************************************************/
# include "amenity.h"

/* *******************************************************
 * implementing the default constructor:
 * initialises with default values
 *********************************************************/
Amenity::Amenity()
{
   // need to be assigned from an input file
   ID = 0;
   state = "";
   county = "";
   avg_temp_jan  = 0.0;
   sunlight_jan  = 0.0;
   avg_temp_july = 0.0;
   avg_humid_july= 0.0;
   landform = 0;
   percent_area_water = 0.0;

   //needs to be computed
   comp_amenity_score = 0.0; 
   count = 0;
}

/* **********************************************************
 * overloading the input operator ">>"
 * to take values directly from the file into Amenity
 * implementing as a friend function as to avoid the need of
 * having setters
 ************************************************************/
ifstream & operator >> (ifstream & fin, Amenity & a)
{
   string eol;
   char ch;           // for ','
   
   // assigning ID
   fin >> a.ID >> ch;

   // counting the total numeber of records read
   a.count++;

   // assigning state via ch
   fin >> ch;
   a.state = ch;   
   fin >> ch;
   a.state += ch;

   // assigning county
   fin >> ch;
   getline(fin, a.county, ',');

   // assigning jan-temperature
   fin >> a.avg_temp_jan >> ch;

   // assigning jan-sunlight
   fin >> a.sunlight_jan >> ch;

   // assigning july-temperature
   fin >> a.avg_temp_july >> ch;

   // assigning humidity
   fin >> a.avg_humid_july >> ch;

   // assigning landform
   fin >> a.landform >> ch;

   // assigning %-water
   fin >> a.percent_area_water;

   return fin;
}

/* **********************************************************
 * compares jan temp of two Amenity instances
 * returns true if LHS->avg_temp_jan > RHS->avg_temp_jan
 ************************************************************/
bool compare_temp_jan(const Amenity & lhs, const Amenity & rhs)
{
   return lhs.get_temp_jan() > rhs.get_temp_jan();
}

/* ***********************************************************
 * comapares jan sunlight of two Amenity instances
 * returns true if LHS->sunlight_jan > RHS->sunlight_jan
 ************************************************************/
bool compare_sun_jan(const Amenity & lhs, const Amenity & rhs)
{
   return lhs.get_sunlight() > rhs.get_sunlight();
}

/* **********************************************************
 * compares july temperatue of two Amenity instances
 * returns true if LHS->avg_temp_july < RHS-avg_temp_july
 ************************************************************/
bool compare_temp_july(const Amenity & lhs, const Amenity & rhs)
{
   return lhs.get_temp_july() < rhs.get_temp_july();
}

/* ************************************************************
 * compares July humidity of two Amenity instances
 * returns true if LHS->avg_humid_july < RHS->avg_humid_july
 **************************************************************/
bool compare_humid_july(const Amenity & lhs, const Amenity & rhs)
{
   return lhs.get_humidity() < rhs.get_humidity();
}

/* ************************************************************
 * compares the landform of two Amenity instances
 * returns true if LHS->landform > RHS->landform
 **************************************************************/
bool comapre_landform(const Amenity & lhs, const Amenity & rhs)
{
   return lhs.get_landform() > rhs.get_landform();
}

/* ******************************************************************
 * compares percent_area_water of two Amenity instances
 * returns true if LHS->percent_area_water > RHS->percent_area_water
 ********************************************************************/
bool compare_water(const Amenity & lhs, const Amenity & rhs)
{
   return lhs.get_percent() > rhs.get_percent();
}
