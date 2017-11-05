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

# include "processFile.h"

/*******************************************************************************************
 * It is used to show how to use the class
 ******************************************************************************************/
void usage()
{
    cout<< endl <<" It takes two command line arguments in the following order:";
    cout<< endl <<" 1. Input file-name";
    cout<< endl <<" 2. Output file-name";
    cout<< endl <<" It replaces the line comments with block comments into the output file.";
    cout<< endl;
}

/*********************************************************************************************
 * It is the execution starting point
 * It uses the version of main which has two input arguments:
 * 1. argC: stores the count of the input arguments
 * 2. argV: is an array of pointer to a constant char
 * It processes the command-line arguments
 * It displays error message and exits on encountering file opening error
 * It uses process_line for converting the file with line comments to block comments
 *********************************************************************************************/
int main(int argC, char * argV[])
{
    bool error = false;
    cout<< endl;
    cout<<" ------------------------------------------------------------------------------------ ";
    cout<< endl;
    if (argC < 2)
      {
	cerr<< endl <<" Insufficient arguments ";
	cout<< endl << argV[0] << ":";
	usage();
	return -1;
	exit(-1);
      }
    ProcessFile p;
    int i = 1;
    for( ; ((i < argC) && (error == false)); i++)
      {
	switch(i)
	  {
	    case 1: 
	           if(!p.set_fileIn(argV[1]))
		      error = true;
		   break;
	    case 2:
	           if(!p.set_fileOut(argV[2]))
		      error = true;
		   break;
	    default:
	            cout<< endl;
	            cout<<" " << argV[0] <<": Only required two command line inputs: 1. INPUT fileName 2. OUTPUT fileName ";
		    cout<< endl << " " << argV[i] << " Not Processed ";
	  }
      }
    if (error)
      {
	cerr<< p.file_error(argV[i-1]);
	return -1;
	exit(-1);
      }
    cout<< endl << " Processing the input file. " << endl;
    p.process_line();
    cout<<" Line comments in file: "<<argV[1]<<" is converted to Block comments in file: "<<argV[2];
    cout<< endl <<" ============================================================================================ " << endl;
    cout<< endl;
    return 0;
}