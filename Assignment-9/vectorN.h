/******************************************************************************************
 * Name    : Rajarshi Sen
 * Z_Id    : z1816768
 * Course  : CSCI 689
 * Section : 1
 * Due Date: May 4, 2017 by midnight
 * Program : to test the template created via this driver program
 * Purpose : to gain experience in of
 *           >dynamic memory allocation
 *           >operator overloading
 *           >templates
 *****************************************************************************************/

/* ********************************************************************************
 * Header file for the class VectorN; which is a template.
 * So, the class definiton and the implementation has to be in the same file:
 * Header file.
 *********************************************************************************/

/* ****************************************************************************
 * template class definition
 *****************************************************************************/
# ifndef TEMPLATE_VECTOR_H
# define TEMPLATE_VECTOR_H

# include <iostream>

using std::ostream;

template <class R>
class VectorN
{
   /* *************************************************
    * private members
    ***************************************************/
   R * data;
   int count;

   /* **************************************************
    * public members
    ***************************************************/
 public:

   /* *****************************************************
    * default constructor
    * takes no argument
    * initializes the container to hold no data
    ******************************************************/
   VectorN();

   /* ****************************************************
    * parameterised constructor
    * takes an integer
    * initializes the container to that size
    ******************************************************/
   VectorN(const int);

   /* ********************************************************
    * parameterized array constructor
    * takes two arguments:
    * >array of data: to be copied into the container.
    * >integer: having the count of elements in the array.
    *********************************************************/
   VectorN(const R *, const int size);

   /* *******************************************************
    * Destructor: as it has dynamic memory
    *********************************************************/
   ~VectorN();

   /* ***********************************************************
    * Copy Constructor:
    * to create an instance from the values of another instance
    *************************************************************/
   VectorN(const VectorN<R> &);

   /* ************************************************************
    * overloading the assignment operator
    **************************************************************/
   VectorN<R> & operator =(const VectorN<R> &);

   /* *****************************************************************************
    * this method properly sets the instance back to a container of zero elements.
    *******************************************************************************/
   void clear();

   /* ******************************************************************************
    * returns the number of elements in the dynamically allocated container
    ********************************************************************************/
   int size()const;

   /* *******************************************************************************
    * overloading the index operator:
    * for reading the value from the container
    ********************************************************************************/
   R operator [](int)const;

   /* ******************************************************************************
    * overloading the index operator again
    * for writing into the container
    *******************************************************************************/
   R & operator [](int);
   
   /* ******************************************************************************
    * overloading the equality "==" operator
    * two instances are equal only if the dynamically allocated container are
    * componetwise equal. For example: (1,2,3) is equal to (1,2,3)
    *******************************************************************************/
   bool operator ==(const VectorN<R> & rhs)const;

   /* *****************************************************************************
    * overloading the addition "+" operator to add two instances
    * The instances are added component wise
    * returns a new instance which is of the same size as the smaller operand
    *******************************************************************************/
   const VectorN<R> operator + (const VectorN<R> &)const;

   /* ******************************************************************************
    * overloading the output operator "<<" function
    * to print out the class
    * according to the required or given format
    *******************************************************************************/
   template<class S>
     friend ostream & operator <<(ostream &, const VectorN<S> &);

};

/* ***************************************************************************************
 * template class implementation
 ****************************************************************************************/

/* *****************************************************
 * default constructor
 * takes no argument
 * initializes the container to hold no data
 ******************************************************/
template<class R>
VectorN<R>::VectorN()
{
   data = nullptr;
   count= 0;
}

/* ****************************************************
 * parameterised constructor
 * takes an integer
 * initializes the container to that size
 ******************************************************/
template<class R>
VectorN<R> :: VectorN(const int size)
{
   data = new R[size];
   count= size;
}

/* ********************************************************
 * parameterized array constructor
 * takes two arguments:
 * >array of data: to be copied into the container.
 * >integer: having the count of elements in the array.
 *********************************************************/
template<class R>
VectorN<R> :: VectorN(const R * src, const int size)
{
   data  = new R[size];
   count = size;
   for(int i = 0; i < size; ++i)
      data[i] = src[i];
}
  

/* ********************************************************
 * Destructor: as it has dynamic memory
 *********************************************************/
template<class R>
VectorN<R> :: ~VectorN()
{
   delete []data;
}


/* ***********************************************************
 * Copy Constructor:
 * to create an instance from the values of another instance
 *************************************************************/
template<class R>
VectorN<R> :: VectorN(const VectorN<R> & rhs)
{
   count = rhs.count;
   data = new R[count];
   for(int i = 0; i < count; ++i)
      data[i] = rhs.data[i];
}

/* ************************************************************
 * overloading the assignment operator
 **************************************************************/
template<class R>
VectorN<R> & VectorN<R> :: operator =(const VectorN<R> & rhs)
{
   // check to self
   if (this == &rhs)
      return *this;

   // delete resources
   delete []data;
   
   // create new resources
   data = new R[rhs.count];

   // copy the values into the new resources
   count = rhs.count;
   for(int i = 0; i < count; ++i)
      data[i] = rhs.data[i];

   /* ******************************************
    * return the reference to current instance
    * it uses non-volatile return optimisation:
    * to avoid the copy overhead
    * need to dereference the current pointer
    ********************************************/
   return *this;
}
  
/* *****************************************************************************
 * this method properly sets the instance back to a container of zero elements.
 *******************************************************************************/
template <class R>
void VectorN<R> :: clear()
{
   delete []data;
   data = nullptr;
   count = 0;
}

/* ******************************************************************************
 * returns the number of elements in the dynamically allocated container
 ********************************************************************************/
template <class R>
int VectorN<R> :: size()const
{
   return count;;
}

/* *******************************************************************************
 * overloading the Subscripting operator:
 * for reading the value from the container
 ********************************************************************************/
template <class R>
R VectorN<R> :: operator [](int index)const
{
   return data[index];
}

/* ******************************************************************************
 * overloading the subscripting operator again
 * for writing into the container
 *******************************************************************************/
template<class R>
R & VectorN<R> :: operator [](int index)
{
   return data[index];
}

/* ******************************************************************************
 * overloading the equality "==" operator
 * two instances are equal only if the dynamically allocated container are
 * componetwise equal. For example: (1,2,3) is equal to (1,2,3)
 *******************************************************************************/
template<class T>
bool VectorN<T> :: operator ==(const VectorN<T> & rhs)const
{
   if(this->count != rhs.count)
      return false;
   for(int i = 0; i < count; ++i)
      if(data[i] != rhs.data[i])
         return false;
   
   return true;
}


/* ******************************************************************************
 * overloading the output operator "<<" function
 * to print out the class
 * according to the required or given format
 *******************************************************************************/
template<class S>
ostream & operator <<(ostream & ostr, const VectorN<S> & v)
{
   ostr<< "[";
   int i = 0;
   for( ; i < v.count-1; ++i)
      ostr<< v.data[i]<< ", ";
   if(i != 0)
      ostr<< v.data[i];
   ostr<< "]";
   
   return ostr;
}

/* *****************************************************************************
 * overloading the addition "+" operator to add two instances
 * The instances are added component wise
 * returns a new instance which is of the same size as the smaller operand
 *******************************************************************************/
template<class R>
const VectorN<R> VectorN<R> :: operator + (const VectorN<R> & rhs)const
{
   // creating new instance
   VectorN<R> sum;
   
   if(this->count < rhs.count)
      sum.count = this->count;
   else
      sum.count = rhs.count;
   
   // creating new resource
   sum.data = new R[sum.count];
   for(int i = 0; i < sum.count; ++i)
      sum.data[i] = this->data[i] + rhs.data[i];
   
   return sum;
}

# endif /* end of TEMPLATE_VECTOR_H */
