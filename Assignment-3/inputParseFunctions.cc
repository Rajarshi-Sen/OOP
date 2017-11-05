/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: February 17, 2017 by midnight
 * Purpose : to parse the user-input and check whether it's positive integer or not.
 ******************************************************************************************/

 /**** Helper Source Code ******************************************************
 * This takes care of:
 * parsing the input 
 * error checking
 * using reference to pass variables
 * returns true or false based on the success of the operation.
 ******************************************************************************/
 
/**** PreProcessor Directives **************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include "assign3HelperFunctions.h"
/****************************************** End of PreProcessor Directives ****/

using std::cout;
using std::endl;
using std::cerr;
using std::stringstream;
using std::string;

string input;
stringstream ss;

/***********************************************************************************************
 * It parses the input.
 * It converts the string input to integer; when the input is numeric.
 * It assigns the generate variables with appropriate values by referencing them.
 * It also checks whether the input is positive by calling checkPositive function.
 * It displays appropriate error message; when needed.
 * Finally it returns true or false based on the results of the operations.
 * userInput: is the reference to the variable having the user-input value.
 * intInput : is the reference to the variable that has to be assigned with user-input value.
 **********************************************************************************************/
bool parseInput(string const & userInput, int & intInput)
{
    bool successFlag;
    ss.clear();
    input = userInput;
    ss << input;
    ss >> intInput;
    if (ss.fail())
      {
	cerr<< endl << " ERROR! " << userInput << " Not an Integer value." << endl << endl;
	successFlag = false;
      }
    else
        successFlag = checkPositive(intInput);
    return successFlag;
}

/****************************************************************************************
  * It returns true or false based on whether refInput is postive or negative.
  * refInput: is the value passed by parseInput function.
 ***************************************************************************************/
bool checkPositive(int const &refInput)
{
    if(refInput > 0)
        return true;
    else
      {
	cerr<< endl << " ERROR! "<< refInput << " Not a POSITIVE integer value." << endl << endl;
        return false;
      }
}
