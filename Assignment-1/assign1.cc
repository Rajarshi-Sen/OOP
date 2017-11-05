/*****************************************************************************
* Name    : Rajarshi Sen
* Z_Id    : z1816768
* Course  : CSCI 689 
* Section : 1
* Due Date: January 27, 2017 by midnight
* Program : To print out a table of wind chill temperatures for selected ranges
*           of air temperatres and wind speed.
********************************************************************************/

/**********************************************************************************
* Instructing the preprocessor to include the following before the compiler runs */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

/****** End of PreProcessor Instructions ****************************************/

using std::cout;
using std::cin;
using std::endl;
using std::setw;

void printWindChillTable(float, float, float, float, float, float);
float calcWindChill(float, float);

int main()
{
/******** Begining of the Program execution **************** 
* It takes input from end-user.
* Checks for errors amongst the values entered by user.
* If the values entered are legal then it calls the printing function;
* otherwise it forms and displays the error message.
* Terminates the program.
***************************** ************************************/

  float tempMax, tempMin, tempDec = 0.0;
  float windMin, windMax, windInc = 0.0;
  cout<< " --------------------------------------------------------------------------------------------";
  cout<< endl << " This program prints out a table of selected wind chill factors" << endl;
  cout<< endl << " Temperature range high value (degrees F) ? ";
  cin >> tempMax;
  cout<< " Temperature range low value  (degrees F) ? ";
  cin >> tempMin;
  cout<< " Temperature decrement (degrees F) ? ";
  cin >> tempDec;
  cout<< " Wind speed low value  (mph) ? ";
  cin >> windMin;
  cout<< " Wind speed high value (mph) ? ";
  cin >> windMax;
  cout<< " Wind speed increment  (mph) ? ";
  cin >> windInc;
  cout<< " ------------------------------------------------------------------------------------------" << endl;
  if ((tempMax > tempMin) && (windMin < windMax) && (tempDec > 0) && (windInc > 0))
    printWindChillTable(tempMax, tempMin, tempDec, windMin, windMax, windInc);
  else
  {
    std::string errorMessage = "";
    if (tempMax < tempMin)
      errorMessage = " ERROR! Illegal Value:  Please make sure that the Temperature ranges from HIGH to LOW \n";
    if (windMin > windMax)
      errorMessage += " ERROR! Illegal Value:  Please make sure that the Wind Speed must range from LOW to HIGH \n";
    if ((tempDec < 0) || (windInc < 0))
      errorMessage += " ERROR! Illegal Value:  Please make sure that the Increment and Decrement values must be POSITIVE \n";

    cout<< errorMessage + " Program Terminated. " << endl;
    cout<< " ------------------------------------------------------------------------------------------" << endl << endl;
  }

  return 0; 
}

void printWindChillTable(float tempMax, float tempMin, float tempDec, float windMin, float windMax, float windInc)
{
/******************** This is the printing function of the program ********************
* It handles all the printing and the formatting requirements such as:-
* Prints the desired output bassed on the input
* Floating point values are printed out with three decimals of precision after the decimal point
* Trailing zeros are printed
* Each floating point value in the table is right justified
* Field width is of nine characters
* It derives the WindChill value by invoking another function
* It prints the formatted result in the design required
* Returns the execution control to the main method
*****************************************************************************************/

  const int width = 9;
  cout<< endl << " Wind Chill Table: " << endl;
  cout<< endl << " Air Temperatre " << endl;
  cout<< setw(width) << "(deg. F)";

  for(float i = tempMax; i >= tempMin; i -= tempDec)
    cout<< setw(width) << std::fixed << std::setprecision(3) << std::showpoint << std::right << i;
  cout<< "\n ------------------------------------------------------------------------------------";
  cout<< endl << " Wind speed" << endl;
  cout<< setw(width) << "(mph)" << endl;

  for(float wind = windMin; wind <= windMax; wind += windInc)
  {
    cout<< setw(width) << wind <<"|";
    for(float temp = tempMax; temp >= tempMin; temp -= tempDec)
      cout<< setw(width) << calcWindChill(temp, wind);
    cout<< endl;
  } 
  cout<< endl <<" -----------------------------------------------------------------------------------" << endl;
  
  return;
}

float calcWindChill(float temp, float wind)
{
/******************** WindChill Calculator *********************************
* Calculates the windchill using the formula given and based on the values received
* Checks for constraints on the wind speed and air temperature
* Returns the WindChill value calculated to the Printing Function
******************************************************************************/

  float windChill = 0.0;
  if ((wind > 3) && (temp < 50))
    windChill = 35.74 + 0.6215 * temp - 35.75 * std::pow(wind,0.16) + 0.4275 * temp * std::pow(wind,0.16);
  else
    windChill = temp;

  return windChill;
}
