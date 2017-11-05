/*******************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689 
 * Section : 1
 * Due Date: February 8, 2017 by midnight
 * Program : To calculate income U.S. tax information for 2016:
 *           calculates the exact tax rate
 *           prints out a tax table that brackets a given income value.
 * Purpose : to use header files and multi-part programs.
 *******************************************************************************/

/**** PreProcessor Directives **************************************************/
#include <iostream>
#include <iomanip>
#include <math.h>
#include "functions.h"
#define  FIELD_WIDTH 12
#define  MID_VALUE 25
/****************************************** End of PreProcessor Directives ****/

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::showpoint;
using std::fixed;
using std::setprecision;

//using std::round;

/**** Begining of the Program execution *****************************************
* This is the main function for assignment2
* It takes he income value as input from end-user using Safe-Input loop.
* It calls the tax calculating functions to print the exact tax.
* It prints the tax table that brackets the given income value.
* It also handles all the output-formatting requirements.
* Terminates the program.
*******************************************************************************/
int main()
{
    float income, tableMidValue = 0.0;
    cout<< endl << " --------------------------------------------------------------" << endl;
    cout<< " Income? ";
    cin >> income;
    while(income <= 0)
      {
	cout<<" Income has to be a positive value for US tax to be calculated; Please Re-Enter. " << endl;
	cout<< endl << endl << " Income? ";
	cin >> income;
      }
    cout<< " Exact tax " << fixed << showpoint << setprecision(2) << endl;
    cout<< " Single:                    " << setw(FIELD_WIDTH) << singleTax(income) << endl;
    cout<< " Married filing jointly:    " << setw(FIELD_WIDTH) << marriedFilingJointlyTax(income) << endl;
    cout<< " Married filing separately: " << setw(FIELD_WIDTH) << marriedFilingSeparatelyTax(income)  << endl;
    cout<< " Head of household:         " << setw(FIELD_WIDTH) << headOfHouseholdTax(income) << endl;
    cout<< endl;
    cout<< setw(FIELD_WIDTH) << "Income" << "  " << setw(FIELD_WIDTH) << "|";
    cout<< setw(FIELD_WIDTH) << " " << setw(FIELD_WIDTH) << "Married";
    cout<< setw(FIELD_WIDTH) << "Married" << setw(FIELD_WIDTH) << "Head" << endl;
    cout<< setw(FIELD_WIDTH) << "Range " << "  " << setw(FIELD_WIDTH) << "|";
    cout<< setw(FIELD_WIDTH) << " " << setw(FIELD_WIDTH) << "Filing" << setw(FIELD_WIDTH) <<  "Filing";
    cout<< setw(FIELD_WIDTH) << "of" << endl;
    cout<< setw(FIELD_WIDTH) << " " << "  " << setw(FIELD_WIDTH) << "|" << setw(FIELD_WIDTH) << "Single";
    cout<< setw(FIELD_WIDTH) << "Jointly" << setw(FIELD_WIDTH) << "Separately";
    cout<< setw(FIELD_WIDTH) << "Household" << endl;
    cout<< "   -------------------------------------------------------------------------- " << endl;

    const float LOOP_INIT = ((int)income/1000)*1000;
    for(float i = LOOP_INIT; i - LOOP_INIT < 1000; i += 50)
      {
	tableMidValue = i + MID_VALUE;
	cout<< setw(FIELD_WIDTH) << (int) i << "-" << setw(FIELD_WIDTH) << (int)(i+50) << "|";
	cout<< setw(FIELD_WIDTH) << (int)(round(singleTax(tableMidValue)));
	cout<< setw(FIELD_WIDTH) << (int)(round(marriedFilingJointlyTax(tableMidValue)));
	cout<< setw(FIELD_WIDTH) << (int)(round(marriedFilingSeparatelyTax(tableMidValue)));
      	cout<< setw(FIELD_WIDTH) << (int)(round(headOfHouseholdTax(tableMidValue)));
	cout<< endl;
      }
    cout<< "   -------------------------------------------------------------------------- " << endl;
    
    return 0;
}
