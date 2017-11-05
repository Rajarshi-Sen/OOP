/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: February 27, 2017 by midnight
 * Program : creating an utility for converting 
 *           Line-style comments to Block-style comments.
 * Purpose : to gain more experience with 
 *         : streams, command line arguments, and lots of decisions.
 *****************************************************************************************/
/******************************************************************************************
 * Header file
 * Pre-processor directives
 * It is protected with Header Guards
 *****************************************************************************************/
# ifndef FILE_H
# define FILE_H

# include <iostream>
# include <fstream>
# include <string>

using std::ifstream;
using std::ofstream;
using std::cerr;
using std::cout;
using std::endl;
using std::string;

/*****************************************************************************************
 * It is the class to process a file with inline comments and generate block comments
 * It has private member variables:
 * 1. fileIn : to take input from file
 * 2. fileOut: to write the output to a file
 * 3. message: to display error to the user
 * 4. data   : to store a line of information
 *
 * It has a public member functions:
 * 1. set_fileIn  : opening the input file.  returns true if it's opened otherwise false.
 * 2. set_fileOut : opening the output file. returns true if it's opened otherwise false.
 * 3. file_error  : userInput --> to refer the file names entered by user
 *				    returns the error message string.
 * 4. process_line: to process the input file and generate the output file with block comments.
 **********************************************************************************************/
 
class ProcessFile
{
    ifstream fileIn;
    ofstream fileOut;
    string message;
    string data;

 public:
    ProcessFile(void){ data = "";} 
	/******************************************************************************************************
	 * inputFile is a reference to a string input by user
	 * it is an inline function used to open the input filestream
	 * returns true on successful opening otherwise false
	 *****************************************************************************************************/
    inline bool set_fileIn (string const & inputFile) { fileIn.open(inputFile);  return fileIn.is_open();}
	/******************************************************************************************************
	 * outputFile is a reference to a string input by user
	 * it is an inline function used to open the input filestream
	 * returns true on successful opening otherwise false
	 *****************************************************************************************************/
    inline bool set_fileOut(string const & outputFile){ fileOut.open(outputFile);return fileOut.is_open();}
	/*******************************************************************************************************
	 * userInput is a reference to the user-input
	 * it is an inline function used to display the error message
	 * returns a reference to the string
	 *******************************************************************************************************/
    inline string & file_error(string const & userInput)
    {
        message = " Unable to open file: " + userInput + "\n Terminating the program. ";
	    return message;
    }
	/*******************************************************************************************************
	 * It processes one line from the input file at a time.
	 * It has access to all the private member variables of the class.
	 ******************************************************************************************************/
    void process_line();
};
# endif /*** end of FILE_H ***/
