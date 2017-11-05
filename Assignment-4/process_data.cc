/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: February 27, 2017 by midnight
 * Function: process_data: to convert- 
 *           Line-style comments to Block-style comments.
 * Purpose : to use the concept of state machines for taking decisions.
 *****************************************************************************************/
# include "processFile.h"

/*******************************************************************************************
 * Global Varaibles
 * skipLine: used to skip a line on encountering a block comment 
 * escape  : used to decide on encountering a back-slash
 ******************************************************************************************/
bool skipLine = false;
const char escape = '\\';

/************************************************************************************************
 * This is the principal function of assignment 4.
 * lineData   : is the reference to a piece of input that is a line from the input file at a time
 * fileOut: is the reference to the output stream used to write the output file
 * It is used to convert line comment to block comment line by line
 * It does not return anything.
 ************************************************************************************************/ 
void process_data(string const & lineData, ofstream & fileOut);

/*******************************************************************************************************
 * It is the member function of ProcessFile
 * It processes one line from the input file at a time.
 * It has access to all the private member variables of the class.
******************************************************************************************************/
void ProcessFile::process_line()
{
    getline(fileIn, data);
    while(!fileIn.eof())
    {
        if (data.length())
	        process_data(data, fileOut);
	    fileOut<< endl;
	    getline(fileIn, data);
    }
    return;
}

/**********************************************************************************************************
 * Implementation of the principal function in this assignment
 * uses a lot of decisions to convert each line from line comment to block comment
 * output: used to store the processed data and put it onto the output file stream
 *********************************************************************************************************/ 
void process_data(string const & lineData, ofstream & fileOut)
{
    char ch;
    string output = "";
    bool found = false;
    bool flag  = false;
    bool skip  = false;
    bool skipCurrent = false;
    for(unsigned int i = 0; i < lineData.length(); i++)
      {
	ch = lineData.at(i);
	if (skipLine && ch != '*')
	  {
	    output += ch;
	    continue;
	  }
	if (skipCurrent)
	  {
	    output += ch;
	    continue;
	  }
	      
	switch(ch)
	  {
	    case '/':
	             if (found && !skip)
		       {
			 output += '*';
			 flag = true;
			 skipCurrent = true;
		       }
		     else
		       {
		         output += ch;
			 found = true;
		       }
		     break;
	    case escape:
		     if(skip)
		        output = output + ch + lineData.at(++i);
		     else
		        output += ch;
		     break;    
	    case '"':
	             if(!skip)
		        skip = true;
		     else
		        skip = false;
		     output += ch;
		     break;
	    case '*':
	             if (i > 0)
		       {
			 if (lineData.at(i-1) == '/' && !skipLine)
			   {
			     skipLine = true;
			     found = false;
			   }
		       }
		     if (i < lineData.length() -1)
		       {
			 if (lineData.at(i+1) == '/' &&  skipLine)
			   {
			     skipLine = false;
			     output += ch;
			     output += lineData.at(++i);
			     break;
			   }
		       }
		     output += ch;
	             break;
	     default:
	             found = false;
		     output += ch;
	  }
      }
    skipCurrent = false;
    if (flag && !skipLine)
        output += " */";       
    fileOut<< output;
    return;
}
