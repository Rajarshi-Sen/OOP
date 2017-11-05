/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: April 18, 2017 by midnight
 * Program : to read a file into set and display them.
 * Purpose : to gain experience with STL set and operator overloading.
 *****************************************************************************************/

/* *******************************************************************************
 * implementation file for the methods in class Assign7
 * also the driver program for the assignment 7 --> main()
 ********************************************************************************/
#include "assign7.h"

int main(int argC, char * argV[])
{
   cout<< endl<<" --------------------------------------------------------------------- "<< endl;
   cout<<" Welcome to Assignment 7: "<< endl;
   cout<<" --------------------------------------------------------------------- "<< endl;
   Assign7 ref_7;
   
   switch(argC)
   {
     case 2:
         break;
     default:
         ref_7.usage();
	 return -1;
   }
   if(!(ref_7.open_file(argV[1])))
     return -1;
   ref_7.read_file();
   ref_7.print_set();
   cout<< " ---------------------------------* End *----------------------------------- "<< endl;
   cout<<endl;
   return 0;
}

/* ********************************************************************
 * implementing the static method: usage
 * explains how to use the class propely
 *********************************************************************/
void Assign7::usage()const
{
   cout<<" Wrong number of command line arguments. Please read below for proper usage: "<<endl;
   cout<<" This class requires an input file via the command line. "<<endl;
   cout<<" It processes the file into a set. "<<endl;
   cout<<" It then prints the elements of the set. "<<endl;
   cout<<" ---------------- Sorry! Please use properly to get the desired results ------------------ "<< endl;
}
   
/* ********************************************************************
 * to open the file:
 * @file_name: is the file name passed via command line argument
 * returns true when file is opened otherwise false.
 *********************************************************************/
bool Assign7::open_file(const string& file_name)
{
   fin.open(file_name);
   if(fin.is_open())
      return true;
   else
   {
      cout<<" Unable to open the file: "<<file_name<<"."<<endl;
      cout<<" ---------------- Sorry! Please give proper file name to get the desired results ------------------ "<< endl;
      return false;
   }
}

/* *******************************************************************
 * implementing the method read_file of class Assign7
 * reads from the input file
 * reads in characters for simplicity
 * also puts them into the set via Container class
 *********************************************************************/
void Assign7::read_file()
{
   string str;
   int key = 0;
   string value = "";
   
   /**************************************************************************
    * 0 for int
    * 1 for string
    * keeping it simple as there in no requirement for extra space checking
    * also trying to avoid "if" to implement faster computing
    **************************************************************************/
   int flag = 0;
   
   fin>>str;
   while(!fin.eof())
   {
       switch(flag)
       {
	  case 0:
	    key = stoi(str);
	    flag = 1;
	    break;
	  case 1:
	    flag = 0;
	    value = str;
	    
            //assigning values to Container instance
	    ref_c = {key, value};
	    
	    //inserting the Container instance into set
	    s_cont.insert(ref_c); 
	    break;
       }
       fin>>str;
   }
   
   /*** closing the file resource ***/
   fin.close();
}

/* *******************************************************************
 * prints the element of the set
 * using iterator, overloaded "[]" and "<<" operator
 *********************************************************************/
void Assign7::print_set()
{
   for(auto i = s_cont.begin(); i != s_cont.end(); ++i)
   {
     if((*i)[0].compare("\\n") == 0)
       cout<<endl;
     else
       cout<< " "<< (*i);
   }
}
