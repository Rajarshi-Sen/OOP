/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: April 26, 2017 by midnight
 * Program : to make the main class for assignment 8
 * Purpose : to gain experience in different ways of
 *           >manipulating Vector
 *           >along with some additional I/O experience.
 *****************************************************************************************/

/* *******************************************************************************
 * implementation file for the methods in class Assign8
 * also the driver program for the assignment 8 --> main()
 ********************************************************************************/
# include "assign8.h"

int main(int argC, char * argV[])
{
   cout<< endl<<" --------------------------------------------------------------------- "<< endl;
   cout<<" Welcome to Assignment 8: "<< endl;
   cout<<" --------------------------------------------------------------------- "<< endl;
   Assign8 ref_8;
 
   switch(argC)
   {
    case 2:
      break;
    default:
      ref_8.usage();
      return -1;
   }

   if(!(ref_8.open_file(argV[1])))
     return -1;
   ref_8.input();
   ref_8.print_count();
   ref_8.calc_composite();
   ref_8.print();
   cout<< " ---------------------------------* End *----------------------------------- "<< endl;
   cout<<endl;
   return 0;
}

/* ********************************************************************
 * implementing the method: usage
 * explains how to use the class propely
 *********************************************************************/
void Assign8::usage()const
{
   cout<<" Wrong number of command line arguments. Please read below for proper usage: "<<endl;
   cout<<" This class requires an input file via the command line. "<<endl;
   cout<<" It processes the file into a vector. "<<endl;
   cout<<" It then prints the elements of the vector using different attributes as sort keys. "<<endl;
   cout<<" ---------------- Sorry! Please use properly to get the desired results ------------------ "<< endl;
}
   
/* ********************************************************************
 * to open the file:
 * @file_name: is the file name passed via command line argument
 * returns true when file is opened otherwise false.
 *********************************************************************/
bool Assign8::open_file(const string& file_name)
{
   fin.open(file_name);
   if(fin.is_open())
      return true;
   else
   {
      cout<<" Unable to open the file: "<<file_name<<"."<<endl;
      cout<<" ---------------- Sorry! Please give proper file name to get the desired results ------------------ "<< endl;
      return false;
   }
}

/* *******************************************************************
 * implementing the method input of class Assign8
 * reads from the input file
 * into class Amenity
 * stores the different Amenitys into a vector
 *********************************************************************/
void Assign8::input()
{
    fin>>amenity;
    while(!fin.eof())
    {
       amenities.push_back(amenity);
       fin>>amenity;
    }
    fin.close();
}

/* ***************************************************************************
 * computes and stores the composite amenity value for each one
 * depends on knowing the average and standard deviation of the
 * individual amenities over the entier vector of amenities
 * **************************************************************************/
void Assign8::calc_composite()
{
   /* *************************************************************************
    * taking the values from vector of amenities into vector of amenity_value
    * one at a time in a loop
    * using algorithm: for_each and a lambda function
    * storing all "average" into an array
    ***************************************************************************/
   vector<float> val;
   val.reserve(amenity.get_count());
   float avg[6];
   float std[6];
   
   for(int i = 0; i < 6; i++)
   {
      val.clear();
      for_each(amenities.begin(), amenities.end(), [&val, i](const Amenity & A){
         switch(i)
         {
            case 0:
	      val.push_back(A.get_temp_jan());
	      break;
	    case 1:
	      val.push_back(A.get_sunlight());
	      break;
	    case 2:
	      val.push_back(A.get_temp_july());
	      break;
	    case 3:
	      val.push_back(A.get_humidity());
	      break;
	    case 4:
	      val.push_back(A.get_landform());
	      break;
	    case 5:
	      val.push_back((log(A.get_percent() * 100)));
	      break;
	 }
      });
      avg[i] = average(val);
      std[i] = std_deviation(val, avg[i]);
   }
   
   /* **************************************************************
    * for the z-score
    * using math utility function 
    * standard for loop
    ****************************************************************/
   float rank;
   for(int i = 0; i < amenity.get_count(); ++i)
   {
      rank = 0.0;
      rank += z_score(amenities[i].get_temp_jan(), avg[0], std[0]);
      rank += z_score(amenities[i].get_sunlight(), avg[1], std[1]);
      rank -= z_score(amenities[i].get_temp_july(), avg[2], std[2]);
      rank -= z_score(amenities[i].get_humidity(), avg[3], std[3]);
      rank += z_score(amenities[i].get_landform(), avg[4], std[4]);
      rank += z_score((log(amenities[i].get_percent() * 100)), avg[5], std[5]);
      amenities[i].score(rank);    
   }
}

/* *******************************************************************
 * prints the element of the vector
 * using the helper class Sort_Print
 * the closely associated function: print_top_bottom_n
 * sort via function pointers or function objects
 *********************************************************************/
void Assign8::print()
{
   /* ****************************************************************************
    * using function pointers as binary predicate into the sort algorithm
    *****************************************************************************/
   const int ROWS = 12;
   
   cout<<"\n Ranking by January Temperature "<< endl;
   cout<<" ========================================================================="<< endl;
   Sort_Print sp(0);
   sort(amenities.begin(), amenities.end(), compare_temp_jan);
   print_top_bottom_n(amenities, ROWS, sp);
   cout<< endl;

   cout<<"\n  Ranking by January Sunshine "<< endl;
   cout<<" ========================================================================="<< endl;
   sp = {1};
   sort(amenities.begin(), amenities.end(), compare_sun_jan);
   print_top_bottom_n(amenities, ROWS, sp);
   cout<< endl;

   cout<<"\n Ranking by July Temperature "<< endl;
   cout<<" ========================================================================="<< endl;
   sp = {2};
   sort(amenities.begin(), amenities.end(), compare_temp_july);
   print_top_bottom_n(amenities, ROWS, sp);
   cout<< endl;

   cout<<"\n  Ranking by July Humidity "<< endl;
   cout<<" ========================================================================="<< endl;
   sp = {3};
   sort(amenities.begin(), amenities.end(), compare_humid_july);
   print_top_bottom_n(amenities, ROWS, sp);
   cout<< endl;

   cout<<"\n Ranking by Landform "<< endl;
   cout<<" ========================================================================="<< endl;
   sp = {4};
   sort(amenities.begin(), amenities.end(), comapre_landform);
   print_top_bottom_n(amenities, ROWS, sp);
   cout<< endl;

   cout<<"\n Ranking by Water Area "<< endl;
   cout<<" =========================================================================="<< endl;
   sp = {5};
   sort(amenities.begin(), amenities.end(), compare_water);
   print_top_bottom_n(amenities, ROWS, sp);
   cout<< endl;

   /* ********************************************************************
    * using Sort_Print as a function object
    * for sorting according to 
    * composite amenity score
    *********************************************************************/
   sp = {6};
   const int N = 10;
   cout<<"\n Composite Ranking "<< endl;
   cout<<" ==========================================================================="<< endl;
   sort(amenities.begin(), amenities.end(), sp);
   print_top_bottom_n(amenities, N, sp);
   cout<< endl;
   
}
