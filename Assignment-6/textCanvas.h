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

/******************************************************************************************
 * Header file for class textCanvas
 * Pre-processor directives
 * It is protected with Header Guards
 *****************************************************************************************/
# ifndef TEXT_CANVAS_H
# define TEXT_CANVAS_H

# include <string>
# include <iostream>

using std::string;
using std::cout;
using std::endl;

/* ***************************************************************************************
 * Global Constants: 
 *****************************************************************************************/
const int CHEIGHT = 24;
const int CWIDTH  = 80;
const int TC_OK = 0;
const int TC_OUT_OF_BOUNDS = -1;
const int TC_CURSOR_OUT_OF_BOX = -2;

/* ****************************************************************************************************
 * The sole purpose of this class is to provide a means of flexibly formatting output on the screen. 
 * Through the use of a textCanvas, 
 * routines can be created to simulate moving the cursor to an arbitrary (x, y) position on the screen.
 * Coordinates in the textCanvas start at (0, 0)
 * in the upper left hand corner and extend in the positive x direction to the right 
 * and in the positive y direction downward. This corresponds naturally to row indices in the 2D array
 * increasing downward and column indices increasing from left to right.
 *******************************************************************************************************/
class textCanvas
{
    /* ********************************************
     * Cursor position:
     *********************************************/
    int row;
    int col;

    /* *********************************************
     * Canvas bounds:
     **********************************************/
    int left;
    int right;
    int top;
    int bottom;

    /* *********************************************
     * 2D array:
     **********************************************/
    char m_array[CHEIGHT][CWIDTH];

    friend class Person;
    
 public:

    /* ************************************************************
     * Default Constructor:
     * clears the array to all spaces
     * sets current cursor position to (0,0), and
     * sets the bounding box boundaries to the edges of the canvas
     **************************************************************/
    textCanvas();

    /* ************************************************************
     * clears the array to all spaces
     * sets current cursor position to (0,0), and
     * sets the the left and top box bounds are set to 0,
     * the right box bound is set to CWIDTH, and
     * the bottom box bound is set to CHEIGHT.
     **************************************************************/
    void clear();

    /* ***********************************************************************************************
     * prints out the 2D array of characters in the current textCanvas instance to the standard output
     **************************************************************************************************/
    void print()const;

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
    int set_box(int l, int t, int w, int h);

    /* *****************************************************************************************************************
     * It is used for drawing a horizontal line
     * @arg:
     * first two integers state the starting position (x,y)
     * third integer specifies the length of the line
     * If the starting or ending bounds of the line fall outside the array boundaries, 
     * this function should return TC_OUT_OF_BOUNDS. Otherwise it should return TC_OK
     ******************************************************************************************************************/
    int print_horizontal_line(int r, int c, int l);

    /* **************************************************************************************************************
     * It is used for drawing a vertical line
     * @arg:
     * first two integers state the starting position (x,y)
     * third integer specifies the height of the line
     * If the starting or ending bounds of the line fall outside the array boundaries,
     * this function should return TC_OUT_OF_BOUNDS. Otherwise it should return TC_OK
     *****************************************************************************************************************/
    int print_vertical_line(int r, int c, int h);

    /* *******************************************************************************************************************
     * This method returns an integer and takes a constant character. 
     * If the character is a '\n', then the function should:
     * increment the cursor row in the current instance and reset the cursor column to the value of the left box boundary.
     * If the character is a '\r', then the function should:
     * simply reset the cursor column to the value of the left box boundary for the current instance.
     * If the current cursor position is not within the box boundaries then return TC_CURSOR_OUT_OF_BOX else TC_OK.
     *********************************************************************************************************************/
    int print_char(const char ch);

    /* ************************************************************************************************************************
     * This method returns an integer and takes as argument a C++ style string. 
     * It simply takes the characters of the string and prints them to the canvas using the print_char() method described above. 
     * It should return the value returned by the last call to print_char().
     ***************************************************************************************************************************/
    int print_string(string str);

};

# endif /* End of TEXT_CANVAS_H */
