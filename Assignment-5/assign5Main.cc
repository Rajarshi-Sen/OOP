/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: March 10, 2017 by midnight
 * Program : to generate report from a collection of data.
 * Purpose : to gain experience in:
 *         : writing simple classes, using C++ vectors, and writing multi-part programs.
 *****************************************************************************************/
# include "assign5.h"

/*******************************************************************************************
 * It is used to show how the class should be used
 ******************************************************************************************/
void usage()
{
  cout<< endl <<" It takes one command line argument: ";
  cout<< endl <<" 1. Input file-name, which contains a collection of storm data.";
  cout<< endl <<" It puts the information into STL vector of Storm. ";
  cout<< endl <<" It prints the data: \n 1. in the order they are specified in the file, ";
  cout<< endl <<" 2. in order of increasing date, \n 3. in order of decreasing wind speed, and ";
  cout<< endl <<" 4. in order of incresing air-pressure.";
  cout<< endl;
  cout<< "==================================================================" << endl;
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
    cout<< endl;
    cout<< "------------------------------------------------------------------------------------ ";
    cout<< endl;
    if (argC < 2)
    {
        cerr<< endl <<" Insufficient arguments ";
        cout<< endl << argV[0] << ":";
        usage();
        return -1;
    }
    ifstream fin;
    fin.open(argV[1]);
    if (!fin.is_open())
    {
	cerr<< " Unable to open the file: " << argV[1];
	return -1;
    }
    Assign5 refAssign;
    Storm ref;
    char userChoice;
    refAssign.read_file(fin, ref);
    cout<< " " << refAssign.get_countRec() << " storms read from " <<  argV[1];
    cout<< endl << " Displaing the data in the order they existed in the file: " << endl;
    refAssign.print();
    cout<< endl <<" Continue to display the data according to increasing date? (Y/N) ";
    cin >> userChoice;
    if (!((userChoice == 'Y') || (userChoice == 'y')))
        return 0;
    cout<< " Sort by date: " << endl;
    refAssign.sort_year();
    cout<< endl << " Continue to display the data according to decreasing wind speed? (Y/N) ";
    cin >> userChoice;
    if (!((userChoice == 'Y') || (userChoice == 'y')))
      return 0;
    cout<< " Sort by wind speed: " << endl;
    refAssign.sort_wind();
    cout<< endl <<" Continue to display the date according to increasing air pressure? (Y/N) ";
    cin >> userChoice;
    if (!((userChoice == 'Y') || (userChoice == 'y')))
       return 0;
    cout<<" Sort by pressure: " << endl;
    refAssign.sort_air();
    cout<< endl;
    cout<< "====XXXX=========================XXXXXXX===========XXXXX=================XXXXXX=================";
    cout<< endl;

    return 0;
}
