/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: April 26, 2017 by midnight
 * Program : math utility functions for
 *         : >finding average over a vector
 *         : >finding standard deviation over a vector
 *****************************************************************************************/

# include "math_vector.h"

/* *************************************************************************
 * calculates and returns the average of a vector of floats
 ***************************************************************************/
float average(const vector<float> & f)
{
   int count = 0;
   float sum = 0.0;
   for_each(f.begin(), f.end(), [&count, &sum](const float value){ ++count; sum += value; });
   return sum/count;
}

/* *************************************************************************
 * calculates and returns the standard deviation
 * @arg: vector of floats and it's average
 **************************************************************************/
float std_deviation(const vector<float> & fv, const float avg)
{
   int count = 0;
   float sum = 0.0;
   for_each(fv.begin(), fv.end(), [&count, &sum, avg](const float value){
       ++count;
       sum += ((value - avg) * (value - avg));
     });
   float variance = sum/(count-1);
   return sqrt(variance);
}

/* *************************************************************************
 * calculates and returns the Z-score of an attribute
 * @arg: attribute value, average, standard_deviation
 ***************************************************************************/
float z_score(const float attr, const float avg, const float std)
{
   return ((attr - avg)/std);
}
