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
 * Pre-processor directive
 ******************************************************************************************/
# include "assign5.h"

/*******************************************************************************************
 * it reads enough to fill up a Storm instance
 * it puts the instance into the vector
 *******************************************************************************************/
void process_data(const string & lineData, Storm & stormRef, vector<Storm> & stormInfo);

/*******************************************************************
 * It builds a valid Heap from the unsorted input array
 * By validating the heap from heapSize/2 to 0 using maxHeapify()
 * As it uses the property:
 * leftChild = 2*index+1
 * rightChild= 2*index+2
 *******************************************************************/
void build_heap(vector<Storm> & stormInfo, char choice);

/********************************************************************
 * for swapping the contents of the indices received
 * index -> is the position where heapify is being done
 * larger-> is the index of the largest child of  the current parent 
 *********************************************************************/
void swap_storm(int index1, int index2, vector<Storm> & stormInfo);

/*******************************************************************
 * It validates the heap at index by recursion
 * index is the position of the currentRoot
*******************************************************************/
void heapify(vector<Storm> & stormInfo, int index, char choice);

int heapSize = 0;

/*************************************************************************************************************
 * fin: is the reference to an open ifstream
 * stormRef: is a reference to an instance of Storm class
 * it processes the input file with the help of 
 * non-member process_data(const string & lineData, Storm & stormRef, vector<Storm> & stormInfo)
 **************************************************************************************************************/
void Assign5::read_file(ifstream & fin, Storm & stormRef)
{
    string data = "";
    getline(fin, data);
    while(!fin.eof())
    {
        if (data.length())
	{
	    ++countRec;
	    process_data(data, stormRef, stormInfo);
	}
        getline(fin, data);
    }
    return;
}

/*******************************************************************************************
 * it reads enough to fill up a Storm instance
 * it puts the instance into the vector
 *******************************************************************************************/
void process_data(const string & lineData, Storm & stormRef, vector<Storm> & stormInfo)
{
    const char space = ' ';
    char ch;
    bool flag = false;
    string output = "";
    int j = -1;
    string info[7];
    for(unsigned int i = 0; i < lineData.length(); ++i)
    {
	ch = lineData.at(i);
	switch(ch)
        {
	  case space:
	       if (flag)
	       {
		  info[++j] = output;
                  output = "";
		  flag = false;
	       }
	       break;
	  default:
	       output += ch;
	       flag = true;
	}
    }
    if (output != "")
       info[++j] = output;
    stormRef = {info[0].at(0), info[6].at(0), stoi(info[2]), stoi(info[3]), stoi(info[5]), stoi(info[4]), info[1]};
    stormInfo.push_back(stormRef);
    return;
}

int  Assign5::get_countRec() const{ return countRec; }

void Assign5:: print_header() const
{
  cout<< endl;
  cout<< left  << setw(header_width) << " Storm" << setw(header_width2) << "Name";
  cout<< right << setw(header_width2) << "Date" << setw(header_width3) << "Wind" << setw(header_width3) << "mbar";
  cout<< endl <<"---------------------------------------------------------------------------------------------------- ";
  cout<< endl;
}

/**************************************************************
 * HeapSort technique begins
 * It builds the maxHeap by calling buildMaxHeap()
 * It then swaps the root with the heapSize
 * It reduces the heapSize by 1
 * It validates the remaining heap using maxHeapify()
 * Repeats from step 2; till heap ends 
 ****************************************************************/
void Assign5::heapSorting()
{
     heapSize = stormInfo.size() - 1;
     build_heap(stormInfo, choice);
     for (int i = heapSize; i > 0; --i)
     {
       swap_storm(0, i, stormInfo);
         heapSize--;
	 heapify(stormInfo, 0, choice);
     }
}

/*******************************************************************
 * It builds a valid Heap from the unsorted input array
 * By validating the heap from heapSize/2 to 0 using maxHeapify()
 * As it uses the property:
 * leftChild = 2*index+1
 * rightChild= 2*index+2
 *******************************************************************/
void build_heap(vector<Storm> & stormInfo, char choice)
{
  for (int currentIndex = ((heapSize) / 2); currentIndex >= 0; currentIndex--)
    heapify(stormInfo, currentIndex, choice);
}

/*******************************************************************
 * It validates the heap at index by recursion
 * index is the position of the currentRoot
*******************************************************************/
void heapify(vector<Storm> & stormInfo, int index, char choice)
{
       int leftChildIndex = (2 * index) + 1;
       int rightChildIndex = (2 * index) + 2;
       int largest = index;
       //if ((leftChildIndex <= heapSize) && (stormInfo[leftChildIndex] > stormInfo[index]))
       if (leftChildIndex <= heapSize)
       {
	   switch(choice)
	   {
	     case 'y':
	       //if(stormInfo[leftChildIndex].get_year == stormInfo[index].get_year())
		    
	         if (stormInfo[leftChildIndex].get_year() > stormInfo[index].get_year())
		     largest = leftChildIndex;
		 
	     case 's':
	        if (stormInfo[leftChildIndex].get_year() == stormInfo[index].get_year())
		  {
		    if(stormInfo[leftChildIndex].get_sequence() > stormInfo[index].get_sequence())
		       largest = leftChildIndex;
		  }
		break;
	     case 'w':
	        if (stormInfo[leftChildIndex].get_max_wind_speed() < stormInfo[index].get_max_wind_speed())
		    largest = leftChildIndex;
	        break;
	     case 'a':
	        if (stormInfo[leftChildIndex].get_min_air_press() > stormInfo[index].get_min_air_press())
		   largest = leftChildIndex;
	        break;
	   }
       }

       // if ((rightChildIndex <= heapSize) && (stormInfo[rightChildIndex] > stormInfo[largest]))
       if (rightChildIndex <= heapSize)
       {
	 switch(choice)
	   {
	     
	   case 'y':
	      if (stormInfo[rightChildIndex].get_year() > stormInfo[largest].get_year())
	         largest = rightChildIndex;
	      //break;
	   case 's':
	      if (stormInfo[rightChildIndex].get_year() == stormInfo[largest].get_year())
	      {
	         if(stormInfo[leftChildIndex].get_sequence() > stormInfo[largest].get_sequence())
		    largest = rightChildIndex;
	      }
	   break;
	   case 'w':
	      if (stormInfo[rightChildIndex].get_max_wind_speed() < stormInfo[largest].get_max_wind_speed())
	          largest = rightChildIndex;
	   break;
	   case 'a':
	      if (stormInfo[rightChildIndex].get_min_air_press() > stormInfo[largest].get_min_air_press())
	          largest = rightChildIndex;
	   break;
	   }
       }
       if (largest != index)
       {
	 swap_storm(index, largest, stormInfo);
	 heapify(stormInfo, largest, choice);
       }
       return;   // returns to the calling method when largest == index (Recursion Limit)
}

/********************************************************************
 * for swapping the contents of the indices received
 * index -> is the position where heapify is being done
 * larger-> is the index of the largest child of  the current parent 
 *********************************************************************/
void swap_storm(int index, int larger, vector<Storm> & stormInfo)
{
       Storm temp = stormInfo[index];
       stormInfo[index] = stormInfo[larger];
       stormInfo[larger] = temp;
}


void Assign5::sort_sequence()
{
    choice = 's';
    int low = 0;
    int max = 0;
    for(unsigned int i = 0; i < stormInfo.size(); )
    {
	int year = stormInfo[i].get_year();
	low = i;
	max = i+1;
	while((stormInfo[++i].get_year() == year) && (i < stormInfo.size()))
	    max++;
	for(; low < max-1; low++)
	{
	    int min = low;
	    for(int j = low+1; j<max; j++)
	      {
		if (stormInfo[j].get_sequence() < stormInfo[min].get_sequence())
		  min = j;
	      }
	    swap_storm(min, low, stormInfo);
	}
    }
}

void Assign5::sort_year()
{
    choice = 'y';
    heapSorting();
    sort_sequence();
    print();
}

void Assign5::sort_wind()
{
    choice = 'w';
    heapSorting();
    print();
}

void Assign5::sort_air()
{
    choice = 'a';
    heapSorting();
    print();
}

void Assign5::print()const
{
    vector<Storm>::const_iterator iterate;
    const int TWENTY = 20;
    int countLine = 0;
    int test = 0;
    print_header();
    for(iterate = stormInfo.cbegin(); iterate != stormInfo.cend(); ++iterate)
    {
	if (countLine == TWENTY)
	{
            print_header();
	    cout<< endl;
	    countLine = 0;
	}
	else
	  countLine++;
	test++;
      	(*iterate).print();
	if (test == 35) break; //testing;
    }
    cout<< endl;
    cout<< "===================================================================================================";
    cout<< endl;

    return;
}
