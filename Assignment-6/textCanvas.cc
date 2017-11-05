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

/* ****************************************************************************************
 * Implementation file for the methods of class textCanvas
 *****************************************************************************************/
# include "textCanvas.h"

/* ************************************************************
 * Default Constructor:
 * clears the array to all spaces
 * sets current cursor position to (0,0), and
 * sets the bounding box boundaries to the edges of the canvas
 **************************************************************/
textCanvas::textCanvas()
{
    for(int i = 0; i < CHEIGHT; i++)
        for(int j = 0; j < CWIDTH; ++j)
            m_array[i][j] = ' ';
    row = 0;
    col = 0;
    left = 0;
    top  = 0;
    right = CWIDTH;
    bottom = CHEIGHT;
}

/* ************************************************************
 * clears the array to all spaces
 * sets current cursor position to (0,0), and
 * sets the the left and top box bounds are set to 0,
 * the right box bound is set to CWIDTH, and
 * the bottom box bound is set to CHEIGHT.
 **************************************************************/
void textCanvas::clear()
{
    row = 0;
    col = 0;
    left = 0;
    top  = 0;
    right = CWIDTH;
    bottom = CHEIGHT;
    for(int i = 0; i < CHEIGHT; i++)
        for(int j = 0; j < CWIDTH; ++j)
	    m_array[i][j] = ' ';
}

/* ***********************************************************************************************
 * prints out the 2D array of characters in the current textCanvas instance to the standard output
 **************************************************************************************************/
void textCanvas::print()const
{
    for(int i = 0; i < CHEIGHT; i++)
    {
	for(int j = 0; j < CWIDTH; j++)
	{
            cout<<m_array[i][j];
	}
	cout<<endl;
    }
}

/* ****************************************************************************************************************
 * this function is used to limit the printing of the print_char() and print_string() methods
 * within the bounding box specified.
 * The bounds are taken as going from the left and top boundaries up to
 * but not including the right and bottom boundaries.
 * For example a bounding box starting at (10, 10)
 * with a width and height of 40 and 7 respectively,
 * would have a left bound of 10, a top bound of 10, a right bound of 50, and a bottom bound of 17.
 * If any of the specified bounds are outside the natural bounds of the 2D array as determined by:
 * 0, CWIDTH, and CHEIGHT, this function should return TC_OUT_OF_BOUNDS, else it should return TC_OK.
 * This routine should also reset the cursor row and column to the left and top bounds of the new bounding box.
 *******************************************************************************************************************/
int textCanvas::set_box(int l, int t, int w, int h)
{
    left = l;
    top  = t;
    right = left + w;
    bottom = top + h;
    if(left >= 0 && top >= 0 && right < CWIDTH && bottom < CHEIGHT && w > 0 && h > 0 )
    {
	row = top;
	col = left;
        return TC_OK;
    }
    return TC_OUT_OF_BOUNDS;
}

/* *****************************************************************************************************************
 * It is used for drawing a horizontal line
 * @arg:
 * first two integers state the starting position (x,y)
 * third integer specifies the length of the line
 * If the starting or ending bounds of the line fall outside the array boundaries,
 * this function should return TC_OUT_OF_BOUNDS. Otherwise it should return TC_OK
 ******************************************************************************************************************/
int textCanvas::print_horizontal_line(int r, int c, int l)
{
    const char h_line = '-';
    int width = r + l;
    if(r < left || c < top || c >= bottom || width >= right)
        return TC_OUT_OF_BOUNDS;
    c++; 
    for(int i = 0; i < l ; i++)
        m_array[c][r++] = h_line;
    return TC_OK;
}

/* **************************************************************************************************************
 * It is used for drawing a vertical line
 * @arg:
 * first two integers state the starting position (x,y)
 * third integer specifies the height of the line
 * If the starting or ending bounds of the line fall outside the array boundaries,
 * this function should return TC_OUT_OF_BOUNDS. Otherwise it should return TC_OK
 *****************************************************************************************************************/
int textCanvas::print_vertical_line(int r, int c, int h)
{
    const char v_line = '|';
    int depth = c + h;
    if(r < left || r >= right || c < top || depth >= bottom)
       return TC_OUT_OF_BOUNDS;
   
    for(int i = 0; i < h; i++)
        m_array[++c][r] = v_line;
    return TC_OK;
}

/* *******************************************************************************************************************
 * This method returns an integer and takes a constant character.
 * If the character is a '\n', then the function should:
 * increment the cursor row in the current instance and reset the cursor column to the value of the left box boundary.
 * If the character is a '\r', then the function should:
 * simply reset the cursor column to the value of the left box boundary for the current instance.
 * If the current cursor position is not within the box boundaries then return TC_CURSOR_OUT_OF_BOX else TC_OK.
 *********************************************************************************************************************/
int textCanvas::print_char(const char ch)
{
    if(row >= bottom || col >= right)
       return TC_CURSOR_OUT_OF_BOX;
  
    switch(ch)
    {
      case '\n':
	row++;
	col = left;
	break;
      case '\r':
	col = left;
	break;
    default:
      m_array[row][col++] = ch;
    }
    return TC_OK;
}

/* ************************************************************************************************************************
 * This method returns an integer and takes as argument a C++ style string.
 * It simply takes the characters of the string and prints them to the canvas using the print_char() method described above.
 * It should return the value returned by the last call to print_char().
 ***************************************************************************************************************************/
int textCanvas::print_string(string str)
{
    int r_value;
    for(unsigned int i = 0; i < str.length(); ++i)
    {
	r_value = print_char(str.at(i));
	switch(r_value)
	{
	  case TC_CURSOR_OUT_OF_BOX:
	    return r_value;
	}
    }
    return r_value;
}
