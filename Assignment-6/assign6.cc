/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: April 7, 2017 by midnight
 * Program : to display a small genealogical database.
 * Purpose : to gain experience in:
 *         : writing simple classes, using C++ vectors, and writing multi-part programs.
 *****************************************************************************************/

# include <fstream>
# include <vector>
# include <iostream>
# include "person.h"
# include "textCanvas.h"

using std::ifstream;
using std::vector;
using std::cin;
using std::cout;
/* ******************************************************************************************
 * It is used to show how to use the class
 ******************************************************************************************/
void usage();

/* ****************************************************************************************
 * reads from the file into a Person--> person_ref via a string array -->file_data
 *****************************************************************************************/
void read_file(ifstream & fin, Person & person_ref);

/* *****************************************************************************************
 * to print the family tree from a given position--> root
 * @arg:
 * tc: reference of the textCanvas class
 * person: vector of Person
 * root: the index 
 ****************************************************************************************/
void print_pedigree(textCanvas & tc, const vector<Person> & person, int root);

/* **************************************************************************************
 * Driver program for assignment 6
 * takes a command line argument: Name of the data file containing the Records.
 * Prints error message and exits, iff number of arguments is wrong.
 **************************************************************************************/
int main(int argC, char * argV[])
{
    ifstream fin;
    vector<Person> persons;
    Person person_ref;
    textCanvas tc;
    char user_command;
    switch(argC)
    {
      case 2:
	  break;
      default:
	usage();
	return -1;
    }
    fin.open(argV[1]);
    if (!fin.is_open())
    {
	cout<<" Unable to open file: "<<argV[1]<<endl;
	cout<< " \n--------------------------------- End --------------------------------------";
	cout<<endl;
	return -2;
    }
    read_file(fin, person_ref);
    while(!fin.eof())
    {
      	persons.push_back(person_ref);
        read_file(fin, person_ref);
    }
    persons.push_back(person_ref);

    cout<< " \n---------------------------------* *-------------------------------------- \n\n";
    print_pedigree(tc, persons, 0);
    cout<< " \n---------------------------------* *-------------------------------------- \n\n";
    cout<<" Move to F)ather, M)other, C)hild or Q)uit? ";
    cin >>user_command;
    cout<< " \n---------------------------------* *-------------------------------------- \n\n";
    int next_root = 0;
    while(user_command != 'q' && user_command != 'Q')
    {
        switch(user_command)
	{
	  case 'f': case 'F':
	    next_root = persons[next_root].get_father();
	    break;
	  case 'm': case 'M':
	    next_root = persons[next_root].get_mother();
	    break;
	  case 'c': case 'C':
	    next_root = persons[next_root].get_child();
	    break;
	}
	if(next_root < 0)
	{
	    cout<<" Sorry data unavailable!!! ";
	    break;
	}
	
	print_pedigree(tc, persons, next_root);
	cout<< " \n---------------------------------* *-------------------------------------- \n\n";
	cout<<" Move to F)ather, M)other, C)hild or Q)uit? ";
	cin >>user_command;
	cout<< " \n---------------------------------* *-------------------------------------- \n\n";
    } 	    
    cout<< " \n--------------------------------- End -------------------------------------- \n\n";
    return 0;
}

/*******************************************************************************************
 * It is used to show how to use the class
 ******************************************************************************************/
void usage()
{
    cout<< " It needs the records file-name as a command line input. "<<endl;
    cout<< " It processes the file into vector of Persons. "<<endl;
    cout<< " \n--------------------------------- End --------------------------------------";
    cout<<endl;
}

/* ****************************************************************************************
 * reads from the file into a Person via a string array -->file_data
 * also assuming that there is no broken record that is
 * for each person there are 17 lines of data.
 *****************************************************************************************/
void read_file(ifstream & fin, Person & person_ref)
{
   const int RECORD_LENGTH = 17;
   string file_data[9];
   string data;
   for(int i = 0; i < RECORD_LENGTH; ++i)
   {
       data = "";
       getline(fin, data);
       switch(i)
       {
	 case 0:
	   file_data[0] = data;
	   break;
	 case 1:
	   file_data[1] = data;
	   break;
	 case 2:
	   file_data[2] = data;
	   break;
	 case 3:
	   file_data[2] = file_data[2] + "#" + data;
	   break;
	 case 4:
	   file_data[2] = file_data[2] + "#" + data;
	   break;
	 case 5:
	   file_data[3] = data;
	   break;
	 case 6:
	   file_data[3] = file_data[3] + "#" + data;
	   break;
	 case 7:
	   file_data[3] = file_data[3] + "#" + data;
	   break;
	 case 8:
	   file_data[4] = data;
	   break;
	 case 9:
	   file_data[4] = file_data[4] + "#" + data;
	   break;
	 case 10:
	   file_data[4] = file_data[4] + "#" + data;
	   break;
	 case 11:
	   file_data[5] = data;
	   break;
	 case 12:
	   file_data[5] = file_data[5] + "#" + data;
	   break;
	 case 13:
	   file_data[5] = file_data[5] + "#" + data;
	   break;
	 case 14:
	   file_data[6] = data;
	   break;
	 case 15:
	   file_data[7] = data;
	   break;
	 case 16:
	   file_data[8] = data;
	   break;
       }
   }
   person_ref = {file_data[0], file_data[1], file_data[2], file_data[3], file_data[4],file_data[5], stoi(file_data[6]), stoi(file_data[7]), stoi(file_data[8])};
}

/* *****************************************************************************************
 * to print the family tree from a given position--> root
 * @arg:
 * tc: reference of the textCanvas class
 * person: vector of Person
 * root: the index
 ****************************************************************************************/
void print_pedigree(textCanvas & tc, const vector<Person> & person, int root)
{
    tc.clear();

    // Print tree diagram

    const int boxwidth = CWIDTH / 3;     // Three generations
    const int boxheight = CHEIGHT / 4;   // Four ancestors in third generation

    const int root_x = 0;
    const int root_y = int(1.5 * boxheight);

    const int father_x = boxwidth;
    const int father_y = int(0.5 * boxheight);

    const int mother_x = boxwidth;
    const int mother_y = int(2.5 * boxheight);

    const int pgf_x = 2 * boxwidth;  // Paternal grandfather
    const int pgf_y = 0;

    const int pgm_x = 2 * boxwidth;  // Paternal grandmother
    const int pgm_y = boxheight;

    const int mgf_x = 2 * boxwidth;  // Maternal grandfather
    const int mgf_y = 2 * boxheight;

    const int mgm_x = 2 * boxwidth;  // Maternal grandmother
    const int mgm_y = 3 * boxheight;


    // Line for root
    tc.print_horizontal_line(root_x, root_y, boxwidth);

    // Horizontal line for father
    tc.print_horizontal_line(father_x, father_y, boxwidth);

    // Horizontal line for mother
    tc.print_horizontal_line(mother_x, mother_y, boxwidth);

    // Horizontal lines for grandparents
    tc.print_horizontal_line(pgf_x, pgf_y, boxwidth);
    tc.print_horizontal_line(pgm_x, pgm_y, boxwidth);
    tc.print_horizontal_line(mgf_x, mgf_y, boxwidth);
    tc.print_horizontal_line(mgm_x, mgm_y, boxwidth);

    // Vertical lines
    tc.print_vertical_line(father_x, father_y, 2 * boxheight);
    tc.print_vertical_line(pgf_x, pgf_y, boxheight);
    tc.print_vertical_line(mgf_x, mgf_y, boxheight);

    // Print the pedigree
    int person_id = root;
    tc.set_box(root_x, root_y, boxwidth, boxheight);
    person[person_id].print(tc);

    // Print father's line
    if(person[person_id].get_father() != -1){
      person_id = person[root].get_father();
      tc.set_box(father_x, father_y, boxwidth, boxheight);
      person[person_id].print(tc);

      if(person[person_id].get_father() != -1){
	tc.set_box(pgf_x, pgf_y, boxwidth, boxheight);
	person[person[person_id].get_father()].print(tc);
      }
      if(person[person_id].get_mother() != -1){
	tc.set_box(pgm_x, pgm_y, boxwidth, boxheight);
	person[person[person_id].get_mother()].print(tc);
      }
    }

    // Print mother's line
    if(person[root].get_mother() != -1){
      person_id = person[root].get_mother();
      tc.set_box(mother_x, mother_y, boxwidth, boxheight);
      person[person_id].print(tc);

      if(person[person_id].get_father() != -1){
	tc.set_box(mgf_x, mgf_y, boxwidth, boxheight);
	person[person[person_id].get_father()].print(tc);
      }
      if(person[person_id].get_mother() != -1){
	tc.set_box(mgm_x, mgm_y, boxwidth, boxheight);
	person[person[person_id].get_mother()].print(tc);
      }
    }

    tc.print();
}
