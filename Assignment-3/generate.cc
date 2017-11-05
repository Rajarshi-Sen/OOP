
/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: February 17, 2017 by midnight
 * Program : to generate a file of random integers based on user-inputs.
 * Purpose : to work with input loops and handle outputting to a file.
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

/**** Begining of the Program execution *****************************************
 * This is the main function for generate program of assignment3
 * It takes input from end-user using safe-input method.
 * It parses the user input via parseInput function.
 * It generates random number and creates the output file via creatFile function. 
 * It checks and displays the error message as appropriate.
 * Terminates the program.
 *******************************************************************************/

int main()
{
    int seed = 0;
    int max = 0;
    int generateCount = 0;
    string fileName = "";

    cout << endl << "----------------------------------------------------------------";
    cout << endl <<" Welcome to the program for Generating the output file: " << endl;
    cout << "----------------------------------------------------------------" << endl;
    while(1)
      {
	string userInput;
	cout<< " Please enter the random number seed: ";
        getline(cin, userInput);
        if (!parseInput(userInput, seed))
	    return -1;
	cout<<" Please enter the upper bound: ";
	getline(cin, userInput);
	if (!parseInput(userInput, max))
	   return -1;
	cout<<" Please enter the number of values to be generated: ";
	getline(cin, userInput);
	if (!parseInput(userInput, generateCount))
	   return -1;
	break;
      }
    cout<<" Please enter the output filename: ";
    getline(cin, fileName);
    if (fileName.empty())
      {
	cerr<<" Warning! No fileName entered. " << endl;
	cout<<" Using 'outputAssign3.dat' as output file name. " << endl;
	fileName = "outputAssign3.dat";
      }
    if(!createFile(seed, max, generateCount, fileName))
      {
	cerr << " Error in File Handling." << endl;
	return -1;
      }
    cout << endl << " Successfully written to the file: " << fileName << endl << endl;
    cout << "===============================================================" << endl;
    return 0;	
}
