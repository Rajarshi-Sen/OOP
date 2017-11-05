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

 /**** Helper Source Code ******************************************************
 * This contains the 4 tax calculating functions
 * Based on each marital/tax status
 * each function takes one argument-->income value
 * returns the floating point value--> the tax
 ******************************************************************************/
 
/**** PreProcessor Directives **************************************************/
#include "functions.h"
/****************************************** End of PreProcessor Directives ****/

float tax = 0.0;
/*******************************************************************************
 * The following function calculates and returns the tax amount
 * For Single that is unmarried People
 * Based on the income slab
 ******************************************************************************/
float singleTax(float income)
{
    if((0 < income) && (income <= 9275))
      {
        tax = 0.1 * income;
      }
    else if((9275 < income) && (income <= 37650))
      {
	tax = 927.50 + (0.15 * (income - 9275));
      }
    else if((37650 < income) && (income <= 91150))
      {
	tax = 5183.75 + (0.25 * (income - 37650));
      }
    else if((91150 < income) && (income <= 190150))
      {
	tax = 18558.75 + (0.28 * (income -  91150));
      }
    else  if((190150 < income) && (income <= 413350))
      {
	tax = 46278.75 + (0.33 * (income - 190150));
      }
    else if((413350 < income) && (income <= 415050))
      {
	tax = 119934.75 + (0.35 * (income - 413350));
      }
    else if(415050 < income)
      {
	tax = 120529.75 + (0.396 * (income - 415050));
      }
    else
      {
	tax = 0.0;
      }

    return tax;
}

/*******************************************************************************
 * The following function calculates and returns the tax amount
 * For Married People Filing Jointly or for Qualifying Widow(er)
 * Based on the income slab
 ******************************************************************************/
float marriedFilingJointlyTax(float income)
{
    if((0 < income) && (income <= 18550))
      {
	tax = 0.1 * income;
      }
    else if((18550 < income) && (income <= 75300))
      {
	tax = 1855.00 + (0.15 * (income - 18550));
      }
    else if((75300 < income) && (income <= 151900))
      {
	tax = 10367.50 + (0.25 * (income  - 75300));
      }
    else if((151900 < income) && (income <= 231450))
      {
	tax = 29517.50 + (0.28 * (income - 151900));
      }
    else if((231450 < income) && (income <= 413350))
      {
	tax = 51791.50 + (0.33 * (income - 231450));
      }
    else if((413350 < income) && (income <= 466950))
      {
	tax = 111818.50 + (0.35 * (income - 413350));
      }
    else if(466950 < income)
      {
	tax = 130578.50 + (0.396 * (income - 466950));
      }
    else
      {
	tax = 0.0;
      }

    return tax;
}

/*******************************************************************************
 * The following function calculates and returns the tax amount
 * For Married People Filing their Tax separately
 * Based on the income slab
 ******************************************************************************/
float marriedFilingSeparatelyTax(float income)
{
    if((0 < income) && (income <= 9275))
      {
	tax = 0.1 * income;
      }
    else if((9275 < income) && (income <= 37650))
      {
	tax = 927.50 + (0.15 * (income - 9275));
      }
    else if((37650 < income) && (income <=  75950))
      {
	tax = 5183.75 + (0.25 * (income - 37650));
      }
    else if((75950 < income) && (income <= 115725))
      {
	tax = 14758.75 + (0.28 * (income - 75950));
      }
    else if((115725 < income) && (income <= 206675))
      {
	tax = 25895.75 + (0.33 * (income - 115725));
      }
    else if((206675 < income) && (income <= 233475))
      {
	tax = 55909.25 + (0.35 * (income - 206675));
      }
    else if(233475 < income)
      {
	tax = 65289.25 + (0.396 * (income - 233475));
      }
    else
      {
	tax = 0.0;
      }

    return tax;
}

/*******************************************************************************
 * The following function calculates and returns the tax amount
 * For the Head of Household
 * Based on the income slab
 ******************************************************************************/
float headOfHouseholdTax(float income)
{
    if((0 < income) && (income <= 13250))
      {
	tax = 0.1 * income;
      }
    else if((13250 < income) && (income <= 50400))
      {
	tax = 1325.00 + (0.15 * (income - 13250));
      }
    else if((50400 < income) && (income <= 130150))
      {
	tax = 6897.50 + (0.25 * (income - 50400));
      }
    else if((130150 < income) && (income <= 210800))
      {
        tax = 26835.00 + (0.28 * (income - 130150));
      }
    else if((210800 < income) && (income <= 413350))
      {
	tax = 49417.00 + (0.33 * (income - 210800));
      }
    else if((413350 < income) && (income <= 441000))
      {
	tax = 116258.50 + (0.35 * (income - 413350));
      }
    else if(441000 < income)
      {
	tax = 125396.00 + (0.396 * (income - 441000));
      }
    else
      {
	tax = 0.0;
      }

    return tax;
}
	    
	  
	    
    
