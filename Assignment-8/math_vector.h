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

# ifndef MATH_VECTOR_H
# define MATH_VECTOR_H

# include <vector>
# include <algorithm>
# include <math.h>

using std::vector;

/* *************************************************************************
 * calculates and returns the average of a vector of floats
 ***************************************************************************/
float average(const vector<float> & f);

/* *************************************************************************
 * calculates and returns the standard deviation
 * @arg: vector of floats and it's average
 **************************************************************************/
float std_deviation(const vector<float> &, const float);

/* *************************************************************************
 * calculates and returns the Z-score of an attribute
 * @arg: attribute value, average, standard_deviation
 ***************************************************************************/
float z_score(const float, const float, const float);

# endif /* end of MATH_VECTOR_H */
