/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: February 17, 2017 by midnight
 * Purpose : to handle file I/O.
 *			 to count the number of values in the file greater than the threshold.
 ******************************************************************************************/

/**** Helper Source Code ******************************************************
 * This takes care of 
 * file  I/O
 * writing the generated random values to the output file.
 * processing the input file to form the report.
 * it checks for error and displays proper message.
 ******************************************************************************/

/**** PreProcessor Directives **************************************************/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#include "assign3HelperFunctions.h"
/****************************************** End of PreProcessor Directives ****/

using std::ofstream;
using std::cerr;
using std::endl;
using std::setw;
using std::cout;
using std::ifstream;

const int valueWidth = 5;
int value = 0;

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
bool createFile(int const seed, int const max, int const generateCount, string const fileName)
{
    ofstream fileOut;
    srand(seed);
    fileOut.open(fileName); 
    if(!fileOut.is_open())
      {
        cerr << endl << " ERROR! Unable to open file" << endl << endl;
	fileOut.close();
        return false;
      }
    for(int i = 0; i < generateCount; i++)
      {
         value = ((float)rand()/RAND_MAX) * max;
	 fileOut << setw(valueWidth) << value << " ";
      }
    fileOut.close();
    return true;
}

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
bool processFile(string const fileName, int const threshValue, int & totalInts, int & ansCount)
{
    ifstream fileIn;
    fileIn.open(fileName);
    if(!fileIn.is_open())
    {
        cerr << endl << " ERROR! Unable to open file" << endl << endl;
	fileIn.close();
        return false;
    }
    fileIn >> value;
    while(!fileIn.eof())
    {
        totalInts++;
        if (value > threshValue)
	   ansCount++;
        fileIn >> value;
    }
    fileIn.close();
    return true;
}
