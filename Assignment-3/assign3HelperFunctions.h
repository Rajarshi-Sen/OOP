/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: February 17, 2017 by midnight
 * Program : 2 programs:
 *           1. to generate a file of random integers based on user-inputs.
 * Purpose : to work with input loops and handle file I/O.
 ******************************************************************************************/

/**** Header file ***************************************************************************
 * This helps to communicate between the different programs of Assignment 3:
 * 1. generate.cc
 * 2. thresh.cc
 * 3. assign3HelperFunctions.cc
 * It contains pre-processor directives and function prototypes.
 ********************************************************************************************/

#include<string>
#ifndef ASSIGN3_HELPER_FUNCTIONS_H
#define ASSIGN3_HELPER_FUNCTIONS_H

using std::string;
/**** Function Prototypes *****************************************************/

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
bool parseInput(string const & userInput, int & integer);

/****************************************************************************************
  * It returns true or false based on whether refInput is postive or negative.
  * refInput: is the value passed by parseInput function.
 ***************************************************************************************/
bool checkPositive(int const & refInput);

/********************************************************************************************
 * It creates the file.
 * It generates the random values based on the input.
 * It stores the values to the output file.
 * It checks for error and displays proper message.
 * It returns true or false based on the success of the operation.
 * seed: is the seed of the random generating function.
 * max : is the upper bound within which the random values need to be generated.
 * generateCount: is the number of random values to be generated.
 * fileName: is the name of the file to be created.
 ********************************************************************************************/
bool createFile(int const seed, int const max, int const generateCount, string const fileName);

/***********************************************************************************************
 * It reads the input file.
 * It forms the required report based on the user-input.
 * It checks for error and displays proper message.
 * It returns true or false based on the success of the operation.
 * fileName   : is the name of the file from which values are to be processed.
 * threshValue: is the threshold value.
 * totalInts  : is the reference to the variable which is assigned the value 
 *   			of the total number of integers found in the file.
 * ansCount   : is the reference to the variable which is assigned the count of
 * 				of the number of values greater than the threshold in the file.
 ************************************************************************************************/ 
bool processFile(string const fileName, int const threshValue, int & totalInts, int & ansCount);

/************************************************ End of required Functions ***********************/

// **** End of Header Guard
# endif 
/******************************************************* End of ASSIGN3_HELPER_FUNCTIONS_H ****/