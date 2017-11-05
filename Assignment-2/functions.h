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

/**** Header file **************************************************************
 * This helps to communicate between the different parts of Assignment 2:
 * 1. The main() --> assign2.cc
 * 2. The helper functions --> functions.cc
 * It contains pre-processor directives and function prototypes.
 *******************************************************************************/

//**** Header Guards ***********************************************************
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**** Function Prototypes *****************************************************/
float singleTax(float income);
float marriedFilingJointlyTax(float income);
float marriedFilingSeparatelyTax(float income);
float headOfHouseholdTax(float income);
/************************************************ End of required Functions ****/

// **** End of Header Guard
# endif 
/******************************************************* End of FUNCTIONS_H ****/
