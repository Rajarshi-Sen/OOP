
/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: February 17, 2017 by midnight
 * Program : to report the count of integers greater than a specified threshold.
 * Purpose : to work with input loops and handle inputting from a file.
 ******************************************************************************************/

/**** PreProcessor Directives **************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "assign3HelperFunctions.h"
/****************************************** End of PreProcessor Directives ****/

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;

/**** Begining of the Program execution *****************************************
 * This is the main function for thresh program of assignment3.
 * It takes input from end-user.
 * It reads the file and forms the report using processFile function. 
 * Finally it displays the report.
 * It also checks for error and displays proper messages.
 * Terminates the program.
 *******************************************************************************/

int main()
{
    string fileName = "";
    int threshold = 0;
    string userInput;
    ifstream fileIn;
    int totalCount = 0;
    int reqCount = 0;

    cout << endl << "-------------------------------------------------------------------------------------------" << endl;
    cout << " Welcome to the program for getting a report of how many values are greater than the user inputted threshold ";
    cout << endl <<"-----------------------------------------------------------------------------------------------" << endl;
    while(1)
      {
	cout << " Please enter the threshold value: ";
	getline(cin, userInput);
	if (!parseInput(userInput, threshold))
	  continue;	
	cout << " Please enter the input filename: ";
	getline(cin, fileName);
        if (fileName.empty())
	  {
	    cerr<< endl <<" Error! No fileName entered. " << endl << endl;
	    continue;
	  }
	break;
      }
    if(!processFile(fileName, threshold, totalCount, reqCount))
        return -1;
    cout << endl << " Report: " << reqCount << " of the " << totalCount << " values in " << fileName << " are greater than " << threshold;
    cout << endl << "================================================================================================" << endl << endl;
    return 0;
}
