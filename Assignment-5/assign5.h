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
/******************************************************************************************
 * Header file
 * Pre-processor directives
 * It is protected with Header Guards
 *****************************************************************************************/
# ifndef ASSIGN5_H
# define ASSIGN5_H

# include <iostream>
# include <fstream>
# include <iomanip>
# include <vector>
# include <string>
# include <algorithm>
# include "Storm.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;
using std::setw;
using std::vector;
using std::stoi;
using std::sort;

class Assign5
{
    vector<Storm> stormInfo;
    const int header_width = 50;
    const int header_width2 = 12;
    const int header_width3 = 10;
    int countRec = 0;
    char choice;
    void sort_sequence();

 public:
 
/*************************************************************************************************************
 * fin: is the reference to an open ifstream
 * stormRef: is a reference to an instance of Storm class
 * it processes the input file with the help of 
 * non-member process_data(const string & lineData, Storm & stormRef, vector<Storm> & stormInfo)
 **************************************************************************************************************/
    void read_file(ifstream & fin, Storm & stormRef);
	
/**************************************************************************************************************
 * it uses the Heap Sort technique to sort the vector of Storm instances
 * takes help of:
 * build_heap(vector<Storm> & stormInfo, char choice);
 * swap_storm(int index1, int index2, vector<Storm> & stormInfo); void heapSorting();
 * heapify(vector<Storm> & stormInfo, int index, char choice); 
 * and the member sort functions
 **************************************************************************************************************/
    void heapSorting();
	
/*************************************************************************************************************
 * it helps to sort the vector of Storm instances by date
 *************************************************************************************************************/
	void sort_year();
	
/*************************************************************************************************************
 * it helps to sort the vector of Storm instances by wind speed
 *************************************************************************************************************/
    void sort_wind();
	
/*************************************************************************************************************
 * it helps to sort the vector of Storm instances by air pressure
 *************************************************************************************************************/
    void sort_air ();
	
/*************************************************************************************************************
 * it helps to retreive the value of member variable countRec
 *************************************************************************************************************/
    int  get_countRec() const;
	
/*************************************************************************************************************
 * it prints the header
 * it promises not to change the instance values
 * also takes care of the necessary output formatting
 *************************************************************************************************************/
    void print_header() const;
	
/*************************************************************************************************************
 * it iterates through the vector of Storm instances and prints the instance values
 * it promises not to change the instance values
 * also takes care of the necessary output formatting
 *************************************************************************************************************/
	void print() const;
};
# endif /*** end of ASSIGN5_H ***/
