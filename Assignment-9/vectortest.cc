/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: May 4, 2017 by midnight
 * Program : to test the template created via this driver program.
 * Purpose : to gain experience in of 
 *           >dynamic memory allocation
 *           >operator overloading
 *           >templates
 *****************************************************************************************/

#include "vectorN.h"
#include <iostream>

using std::cout;
using std::endl;

#include <string>
using std::string;

int  main()
{
  int test = 1;

  cout << "\nTest " << test++ << ": Default constructor and printing\n" << endl;

  const VectorN<int>  v1;

  cout << "v1: " << v1 << endl;

  cout << "\nTest " << test++ << ": Array constructor and printing\n" << endl;

  const float ar2[] = {11.6, -2.3, 23.45};

  const VectorN<float> v2(ar2, 3);

  cout << "v2: " << v2 << endl;

  cout << "\nTest " << test++ << ": Clear and size\n" << endl;
  VectorN<float> v3(ar2, 3);
  
  cout << "The size of v3: " << v3 << " is " << v3.size() << endl;

  v3.clear();

  cout << "After clearing, the size of v3: " << v3 << " is ";
  cout << v3.size() << endl;
  
  cout << "\nTest " << test++ << ": Subscripting\n" << endl;

  const string ar3[] = {"First", "Second", "Third", "Fourth", "Fifth"};
  const VectorN<string> v4(ar3, 5);

  cout << "v4: " << v4 << endl;
  cout << "v4[0]: " << v4[0] << "  v4[1]: " << v4[1] << endl;
  cout << "v4[2]: " << v4[2] << "  v4[3]: " << v4[3] << endl;
  cout << "v4[4]: " << v4[4] << endl;
  
  VectorN<string> v5(ar3, 5);
  v5[0] = "Sixth";  v5[1] = "Seventh";  v5[2] = "Eighth";  v5[3] = "Ninth";
  cout << "v5: " << v5 << endl;

  cout << "\nTest " << test++ << ": Copy constructor\n" << endl;
  
  const VectorN<float> v6(ar2, 3);
  const VectorN<float> v7 = v6;

  cout << "v6: " << v6 << " size: " << v6.size() << endl;
  cout << "v7: " << v7 << " size: " << v7.size() << endl;

  VectorN<string> v8(ar3, 5);
  VectorN<string> v9 = v8;

  cout << "v8: " << v8 << " size: " << v8.size() << endl;
  cout << "v9: " << v9 << " size: " << v9.size() << endl;

  v8[1] = "Test";
  cout << "Changing..." << endl;
  cout << "v8: " << v8 << " size: " << v8.size() << endl;
  cout << "v9: " << v9 << " size: " << v9.size() << endl;

  cout << "\nTest " << test++ << ": Assignment operator\n" << endl;
  VectorN<string> v10(ar3, 5);
  VectorN<string> v11;

  cout << "v10: " << v10 << endl;
  cout << "v11: " << v11 << endl;

  v11 = v10;

  v10[0] = "Zeroth";

  cout << "v10: " << v10 << endl;
  cout << "v11: " << v11 << endl;

  cout << endl;

  // Chained assignment
  VectorN<string> v12, v13;

  cout << "v11: " << v11 << endl;
  cout << "v12: " << v12 << endl;
  cout << "v13: " << v13 << endl;

  v13 = v12 = v11;
  v11[0] = "Success?";

  cout << "v11: " << v11 << endl;
  cout << "v12: " << v12 << endl;
  cout << "v13: " << v13 << endl;

  cout << endl;

  // Assignment to self

  v13 = v13;

  VectorN<float> v14(ar2, 3);

  cout << "v13: " << v13 << endl;


  
  cout << "\nTest " << test++ << ": Equality\n" << endl;

  const int ar6[] = {2, 3, 3};
  const int ar7[] = {2, 3, -3};
  const int ar8[] = {2, 3, 3, 0};
  const int ar9[] = {2, 3, -3, 0};

  const VectorN<int> v18(ar6, 3), v19(ar7, 3);
  const VectorN<int> v20(ar8, 4), v21(ar9, 4);

  cout << v18 << " and " << v18 << " are ";

  if(v18 == v18)
    cout << "equal" << endl;

  else
    cout << "not equal" << endl;

  
  cout << v18 << " and " << v19 << " are ";

  if(v18 == v19)
    cout << "equal" << endl;

  else
    cout << "not equal" << endl;
  
  cout << v18 << " and " << v20 << " are ";

  if(v18 == v20)
    cout << "equal" << endl;

  else
    cout << "not equal" << endl;
  
  cout << v21 << " and " << v19 << " are ";

  if(v21 == v19)
    cout << "equal" << endl;

  else
    cout << "not equal" << endl;

  // Addition operator

  cout << "\nTest " << test++ << ": Addition\n" << endl;

  const int ar10[] = {-5, 2, 6, 14, 0, 0, -6, 8};
  const int ar11[] = {2, 9, -3, 7, 8, -1, 2};

  const VectorN<int> v22(ar10, 8);
  const VectorN<int> v23(ar11, 7);

  VectorN<int> v24;

  v24 = v22 + v23;

  cout << "v22: " << v22 << endl;
  cout << "v23: " << v23 << endl;
  cout << "v24 (v22+v23): " << v24 << endl;

  v24 = v23 + v22;

  cout << "v22: " << v22 << endl;
  cout << "v23: " << v23 << endl;
  cout << "v24 (v23 + v22): " << v24 << endl << endl;

  const string ar12[] = {"Holly", "surf", "face", "light"};
  const string ar13[] = {"wood", "board", "book", "house"};

  const VectorN<string> v25(ar12, 4);
  const VectorN<string> v26(ar13, 4);

  cout << "v25: " << v25 << endl;
  cout << "v26: " << v26 << endl;
  cout << "v25+v26: " << v25 + v26 << endl;
  
  return 0;
}
