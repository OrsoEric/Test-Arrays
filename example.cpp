/****************************************************************
**	OrangeBot Project
*****************************************************************
**        /
**       /
**      /
** ______ \
**         \
**          \
*****************************************************************
**	Test Arrays
*****************************************************************
**	Test all the ways one can make an array in C++
**	C++11 standard
****************************************************************/

/****************************************************************
**	DESCRIPTION
****************************************************************
**	How to store vectors and arrays in C++.
**
**	MEMORY
**	There are two storage methods. Stack and heap.
**		STACK is local and content is destroyed when array goes out of scope
**		HEAP is global and allocated dynamically. Has overhead, can fail, but can change in size and is easy and fast to pass as argument.
**
**
****************************************************************/

/****************************************************************
**	HISTORY VERSION
****************************************************************
**
****************************************************************/

/****************************************************************
**	KNOWN BUGS
****************************************************************
**
****************************************************************/

/****************************************************************
**	TODO
****************************************************************
**
****************************************************************/

/****************************************************************
**	INCLUDES
****************************************************************/

//Standard C libraries
#include <cstdlib>		//for malloc, free
#include <cstring>		//for std::memmove
//Standard C++ libraries
#include <iostream>		//for cout, endl
#include <array>		//for std::array

/****************************************************************
**	NAMESPACES
****************************************************************/

using std::cout;	//print to console
using std::cerr;	//print to console
using std::endl;	//new line
using std::array;	//stack based array with size and type known at compile time
using std::memcpy;	//move bytes from one place to the other. Fastest but does no check.
using std::memmove;	//move bytes from one place to the other taking care of overlap
using std::strcpy;	//copy two strings
using std::copy;	//copy from palce to place using iterators

/****************************************************************
**	DEFINES
****************************************************************/

/****************************************************************
**	MACROS
****************************************************************/

/****************************************************************
**	PROTOTYPES
****************************************************************/

///C Style, Stack, 1D
extern void c_style_stack_1d( void );
extern void c_style_stack_1d_handler( int *array_arg, int size );

///C Style, Stack, 2D
extern void c_style_stack_2d( void );
//There are two ways to pass a local multidimensional array
//	Option 1: pass the EXPLICIT address of the first element and size information. A multidimensional array is stored in a single contiguous vector. Index=r*#C+c
extern void c_style_stack_2d_handler_pointer( int *array_arg, int size, int rows );
//	Option 2: pass to the type with the right number of columns
extern void c_style_stack_2d_handler_type( int array_arg[][5], int size, int rows );

///C++, std::array, stack, 1D
extern void cpp_std_array_stack_1d( void );
//	There is no easy way to pass a std:arry as argument. There are two ways to do it.
//	Option 1: you make a template function template <typename T, std::size_t S>
template <typename T, int S>
extern void cpp_std_array_stack_1d_handler_template( std::array<T,S> array_arg );
//	Option 2: you make a function that takes two iterators. Begin and end of the array.
//template <typename T, std::size_t S>
//extern void cpp_std_array_stack_1d_handler_iterator( typename std::array<T,S>::iterator begin, typename std::array<T,S>::iterator end );
template <class RandomAccessIterator>
extern void cpp_std_array_stack_1d_handler_iterator(RandomAccessIterator first, RandomAccessIterator last);

///C++ std::array, stack, 2D
extern void cpp_std_array_stack_2d( void );
//As for the one dimensional case there is no easy solution to pass the array.
//Option 0 is to pass it as you would a C array with pointer and dimensions. I can use the function written before
//extern void cpp_std_array_stack_1d_handler_pointer( int *array_arg, int num_rows, int num_cols );
//Option 1 is to use a template specialization to pass the right type
template <typename T, int R, int C>
extern void cpp_std_array_stack_2d_handler_template( array<array<int,C>,R> array_arg );
//Option 2

///C STYLE, HEAP MALLOC, 1 DIMENSION
extern void c_style_heap_1d( void );

///C STYLE, HEAP MALLOC, 2 DIMENSION
extern void c_style_heap_2d( void );

///C++ STYLE, HEAP NEW, 1 DIMENSION
extern void cpp_style_heap_1d( void );

///C++ STYLE, HEAP NEW, 2 DIMENSIONS
extern void cpp_style_heap_2d( void );

/****************************************************************
**	GLOBAL VARIABILE
****************************************************************/

/****************************************************************
**	FUNCTIONS
****************************************************************/

/****************************************************************
**	MAIN
****************************************************************
**	INPUT:
**	OUTPUT:
**	RETURN:
**	DESCRIPTION:
****************************************************************/

int main()
{
	///----------------------------------------------------------------
	///	STATIC VARIABILE
	///----------------------------------------------------------------

	///----------------------------------------------------------------
	///	LOCAL VARIABILE
	///----------------------------------------------------------------

	///----------------------------------------------------------------
	///	CHECK AND INITIALIZATIONS
	///----------------------------------------------------------------

	///----------------------------------------------------------------
	///	BODY
	///----------------------------------------------------------------
	//	MEMORY
	//	Stack based solution
	//		fast
	//		does not require allocation
	//	Heap based solution
	//		dynamic size
	//		content not limited by scope
	//		do not need to know size at compile time
	//
	//	DIMENSION
	//

	cout << "OrangeBot Projects\n" << endl;

		///----------------------------------------------------------------
		///	C STYLE, STACK, 1 DIMENSION
		///----------------------------------------------------------------
		//	Size must be known at compile time
		//	you can get the size in the same scope it's declared, but not out of scope
		//	array is just a pointer to the first element
		//	array cotent is local and is destroyed when it goes out of scope
		//	array cannot change size but content can be edited

	cout << endl << "------------------------" << endl;
	cout << "C STYLE, STACK, 1 DIMENSION" << endl;
	c_style_stack_1d();

		///----------------------------------------------------------------
		///	C STYLE, STACK, 2 DIMENSIONS
		///----------------------------------------------------------------
		//	Initialization is straightforward

	cout << endl << "------------------------" << endl;
	cout << "C STYLE, STACK, 2 DIMENSIONS" << endl;
	c_style_stack_2d();

		///----------------------------------------------------------------
		///	STD::ARRAY, STACK, 1 DIMENSION
		///----------------------------------------------------------------
		//	It's a thin wrapper of the C style declaration.
		//	It has all limitation of a stack based solution
		//	It as the advantage of not requiring allocation and being fast
		//	It provides a method
		//	There is no easy way to pass a std:arry as argument.
		//	Either you make a template function template <typename T, std::size_t S>
		//	Or you make a function that takes two iterators. Begin and end of the array.

	cout << endl << "------------------------" << endl;
	cout << "STD::ARRAY, STACK, 1 DIMENSION" << endl;
	cpp_std_array_stack_1d();

		///----------------------------------------------------------------
		///	STD::ARRAY, STACK, 2 DIMENSIONS
		///----------------------------------------------------------------
		//	You can make an array of arrays since the container std::array is generic

	cout << endl << "------------------------" << endl;
	cout << "STD::ARRAY, STACK, 2 DIMENSIONS" << endl;
	cpp_std_array_stack_2d();

		///----------------------------------------------------------------
		///	C STYLE, HEAP MALLOC, 1 DIMENSION
		///----------------------------------------------------------------

	cout << endl << "------------------------" << endl;
	cout << "C STYLE, HEAP MALLOC, 1 DIMENSION" << endl;
	c_style_heap_1d();

		///----------------------------------------------------------------
		///	C STYLE, HEAP MALLOC, 2 DIMENSION
		///----------------------------------------------------------------

	cout << endl << "------------------------" << endl;
	cout << "C STYLE, HEAP MALLOC, 2 DIMENSIONS" << endl;
	c_style_heap_2d();

		///----------------------------------------------------------------
		///	C++ STYLE, HEAP NEW, 1 DIMENSION
		///----------------------------------------------------------------

	cout << endl << "------------------------" << endl;
	cout << "C++ STYLE, HEAP NEW, 1 DIMENSION" << endl;
	cpp_style_heap_1d();

		///----------------------------------------------------------------
		///	C++ STYLE, HEAP NEW, 2 DIMENSION
		///----------------------------------------------------------------

	cout << endl << "------------------------" << endl;
	cout << "C++ STYLE, HEAP NEW, 2 DIMENSION" << endl;
	cpp_style_heap_2d();

		///----------------------------------------------------------------
		///	STD::VECTOR, HEAP NEW, 1 DIMENSION
		///----------------------------------------------------------------



	///----------------------------------------------------------------
	///	FINALIZATIONS
	///----------------------------------------------------------------

    return 0;
}	//end function: main

/****************************************************************************
**	c_style_stack_1d_array
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	C-Style 1 dimensional array that is stored in stack
****************************************************************************/

void c_style_stack_1d( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	int num_elem;
	int my_initialized_1d_stack_array[] = { 0, 10, 9, 1, 8, 2, 7, 3, 6, 4, 5 };
	//int my_uninitialized_1d_stack_array[10];

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	cout << "C Style 1 Dimensional Stack Array" << endl;

	//Compute size of the initialized array
	//It's number of byte of the array divided by the size of the single element
	//Can only be done in the same scope the array is created
	num_elem = sizeof( my_initialized_1d_stack_array ) /sizeof(int);
	cout << "Number of elements: " << num_elem << endl;

	//Pass the array to an handling function
	//This needs the pointer to the first element and the size of the array
	c_style_stack_1d_handler( my_initialized_1d_stack_array, num_elem );

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function: c_style_stack_1d

/****************************************************************************
**	c_style_stack_1d_array_handler
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**
****************************************************************************/

void c_style_stack_1d_handler( int *array_arg, int size )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	int num_elem;
	//fast counter
	register int t;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	cout << ">>passing array to an handling function" << endl;

	//Try to compute the size anyway. Spoiler: this does not work. It compute the size of the pointer itself
	num_elem = sizeof( array_arg ) /sizeof(int);

	cout << "Given size: " << size << " | " << "Computed size: " << num_elem << endl;
	cout << "Cant compute size of this array outside the scope it was declared" << endl;

	array_arg[1] = -99;
	cout << "element[2]= -99 | content can be edited" << endl;

	cout << "CONTENT" << endl;

	for (t = 0;t < size;t++)
	{
		cout << array_arg[t] << " | ";
	}

	cout << endl;

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function: c_style_stack_1d_handler

/****************************************************************************
**	C STYLE, STACK, 2 DIMENSIONS
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

void c_style_stack_2d( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//My array
	int my_initialized_1d_stack_array[][5] = { { 0, 9, 1, 8, 2 }, { 7, 3, 6, 4, 5 } };
	//size of the array
	int size;
	//rows of the bidimensional array
	int rows;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------


	cout << "C Style 2 Dimensional Stack Array" << endl;
	//number of rows
	rows = 5;
	//Compute size of the array
	size = sizeof(my_initialized_1d_stack_array)/sizeof(int);
	cout << "Number of elements: " << size << endl;
	//Pass reference to the array to an handler
	c_style_stack_2d_handler_pointer( &my_initialized_1d_stack_array[0][0], size, rows );
	//Pass to a function that accept the right type, down to the number of columns
	c_style_stack_2d_handler_type( my_initialized_1d_stack_array, size, rows );

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function:	c_style_stack_2d

/****************************************************************************
**	c_style_stack_2d_handler_pointer
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	Option 1: pass the EXPLICIT address of the first element and size information. A multidimensional array is stored in a single contiguous vector. Index=r*#C+c
****************************************************************************/

void c_style_stack_2d_handler_pointer( int *array_arg, int size, int rows )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//fast counters
	register int t, ti;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	cout << ">>pass by reference to first element" << endl;

	cout << "CONTENT" << endl;
	for (t = 0;t < size/rows;t++)
	{
		for (ti = 0;ti < rows;ti++)
		{
			//The array is sequenced into a single vector
			//Compute the index of the element
			cout << array_arg[t*rows +ti] << " | ";
		}
		cout << endl;
	}

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function: c_style_stack_2d_handler_pointer | int *, int, int

/****************************************************************************
**	c_style_stack_2d_handler_type
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	Option 2: pass to the type with the right number of columns
**	you still can't get the array dimension
****************************************************************************/

void c_style_stack_2d_handler_type( int array_arg[][5], int size, int rows )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//fast counters
	register int t, ti;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	cout << ">>pass by using the correct multidimensional type" << endl;

	cout << "CONTENT" << endl;
	for (t = 0;t < size/rows;t++)
	{
		for (ti = 0;ti < rows;ti++)
		{
			//The array is sequenced into a single vector
			//Compute the index of the element
			cout << array_arg[t][ti] << " | ";
		}
		cout << endl;
	}

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function: c_style_stack_2d_handler_type | int [][5]

/****************************************************************************
**	cpp_std_array_stack_1d
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

void cpp_std_array_stack_1d( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

    //must know the numbers of element before hand
	array<int,11> my_initialized_1d_stack_array = { 0, 10, 9, 1, 8, 2, 7, 3, 6, 4, 5 };

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//Pass array as a whole (pass values). Require template to specialize the handler to the right type.
	cpp_std_array_stack_1d_handler_template<int,11>( my_initialized_1d_stack_array );

	//Dark magic involving C++ RandomAccessIterator class. Does not require specialization. Pass by reference.
	cpp_std_array_stack_1d_handler_iterator( my_initialized_1d_stack_array.begin(), my_initialized_1d_stack_array.end() );

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function: cpp_std_array_stack_1d

/****************************************************************************
**	cpp_std_array_stack_1d_handler_template
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**
****************************************************************************/

template <typename T, int S>
void cpp_std_array_stack_1d_handler_template( array<T, S> array_arg )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	int num_elem;
	//fast counter
	register int t;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	cout << ">>passing std::array to an handling function as a whole" << endl;

	//Try to compute the size anyway. Spoiler: this does not work. It compute the size of the pointer itself
	num_elem = array_arg.size();

	cout << "Given size: " << num_elem << endl;
	cout << "Cant compute size of this array outside the scope it was declared" << endl;

	array_arg[1] = -99;
	cout << "element[2]= -99 | content can be edited" << endl;

	cout << "CONTENT" << endl;

	for (t = 0;t < S;t++)
	{
		cout << array_arg[t] << " | ";
	}

	cout << endl;

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function: cpp_std_array_stack_1d_handler_template

/****************************************************************************
**	cpp_std_array_stack_1d_handler_iterator | RandomAccessIterator, RandomAccessIterator
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	Iterator objects have a rather verbose type
**	 a future C++17 standard will probably allow for auto to be used as type parameter
**	I can use the class RandomAccessIterator for the iterator type
****************************************************************************/

//template <typename T, std::size_t S>
//void cpp_std_array_stack_1d_handler_iterator( typename std::array<T,S>::iterator first, typename std::array<T,S>::iterator last )
template <class RandomAccessIterator>
extern void cpp_std_array_stack_1d_handler_iterator(RandomAccessIterator first, RandomAccessIterator last)
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	cout << ">>passing std::array iterators to an handling function" << endl;

	cout << "CONTENT" << endl;
	for (;first <= last;first++)
	{
		cout << *first << " | ";
	}

	cout << endl;

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function: cpp_std_array_stack_1d_handler_iterator | RandomAccessIterator, RandomAccessIterator

/****************************************************************************
**	cpp_std_array_stack_2d | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	Under C11 you need an extra pair of braces around the outer dimension.
**	You would need braces around inner dimension too, but brace-elision kicks in
**	allowing you to declare 1 dimensional std::arrays and inner dimensions of std::arrays
**	as you would with C
****************************************************************************/

void cpp_std_array_stack_2d( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

    //must know the numbers of element before hand
	array<array<int,5>,2> my_initialized_1d_stack_array = { { {0, 9, 1, 8, 2}, {7, 3, 6, 4, 5} } };

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//Option 0 is to pass it as you would a C array with pointer and dimensions. I can use the function written before
	c_style_stack_2d_handler_pointer( &my_initialized_1d_stack_array[0][0], 5*2, 5 );

	//Option 1 Pass array as a whole (pass values). Require template to specialize the handler to the right type.
	cpp_std_array_stack_2d_handler_template<int,2,5>( my_initialized_1d_stack_array );

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function: cpp_std_array_stack_2d | void

/****************************************************************************
**	cpp_std_array_stack_1d_handler_template | std::array<std::array<int,C>,R>
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	Option 1 is to use a template specialization to pass the right type
**	Nice because it allows to use bracers without writing translation of address by hand
****************************************************************************/

template <typename T, int R, int C>
void cpp_std_array_stack_2d_handler_template( array<array<int,C>,R> array_arg )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	int num_elem;
	//fast counter
	register int t, ti;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	cout << ">>passing std::array to an handling function as a whole" << endl;

	//Try to compute the size anyway. Spoiler: this does not work. It compute the size of the pointer itself
	num_elem = array_arg.size();

	cout << "Given size: " << num_elem << endl;
	cout << "Cant compute size of this array outside the scope it was declared" << endl;

	cout << "CONTENT" << endl;

	for (t = 0;t < R;t++)
	{

		for (ti = 0;ti < C;ti++)
		{
			cout << array_arg[t][ti] << " | ";
		}
		cout << endl;
	}

	cout << endl;

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function: cpp_std_array_stack_1d_handler_template | std::array<std::array<int,C>,R>

/****************************************************************************
**	c_style_heap_1d | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	allocate with malloc
**	pass pointer and size to handling function
**	deallocate with free
****************************************************************************/

void c_style_heap_1d( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//Content of the array
	int my_initialized_1d_stack_array[] = { 0, 10, 9, 1, 8, 2, 7, 3, 6, 4, 5 };
	//Pointer to array
	int *my_heap_array = NULL;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	cout << "Allocate array with malloc" << endl;
	//Allocate the array
	my_heap_array = (int *)malloc( 11 *sizeof(int) );

	if (my_heap_array == NULL)
	{
		cerr << "malloc failed" << endl;
		exit(-1);
	}
	//Copy 11 bytes from the constant array to the heap array
	memmove( my_heap_array, my_initialized_1d_stack_array, 11 *sizeof(int) );

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//Can reuse the handler written previously
	c_style_stack_1d_handler( my_heap_array, 11 );

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	cout << "Deallocate array" << endl;

	//Free the memory
	free( my_heap_array );
	my_heap_array = NULL;

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function: c_style_heap_1d | void

/****************************************************************************
**	c_style_heap_2d | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	There are two ways of doing things.
**	Either make an array of pointers to arrays
**	or make an array and use subscript to
****************************************************************************/

void c_style_heap_2d( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function: c_style_heap_2d | void

/****************************************************************************
**	cpp_style_heap_1d | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	C++ STYLE, HEAP NEW, 1 DIMENSION
****************************************************************************/

void cpp_style_heap_1d( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//Content of the array
	int my_initialized_1d_stack_array[] = { 0, 10, 9, 1, 8, 2, 7, 3, 6, 4, 5 };
	//Pointer to array
	int *my_heap_array = NULL;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	cout << "Allocate array with new" << endl;
	//Allocate the array
	my_heap_array = new int[11];

	if (my_heap_array == NULL)
	{
		cerr << "malloc failed" << endl;
		exit(-1);
	}
	//Copy 11 bytes from the constant array to the heap array
	memmove( my_heap_array, my_initialized_1d_stack_array, 11 *sizeof(int) );

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//Can reuse the handler written previously
	c_style_stack_1d_handler( my_heap_array, 11 );

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	cout << "Deallocate array" << endl;

	//Free the memory
	delete( my_heap_array );
	my_heap_array = NULL;

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function: cpp_style_heap_1d | void

/****************************************************************************
**	cpp_style_heap_2d | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	new int[2][5] can only be used if dimensions are known at compile time
****************************************************************************/

void cpp_style_heap_2d( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//Content of the array
	int my_initialized_2d_stack_array[][5] = { { 0, 9, 1, 8, 2 }, { 7, 3, 6, 4, 5 } };
	//Pointer to array
	int *my_heap_array = NULL;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	cout << "Allocate array with new" << endl;
	//Allocate the array
	my_heap_array = new int[2 *5];

	if (my_heap_array == NULL)
	{
		cerr << "malloc failed" << endl;
		exit(-1);
	}
	//Copy 11 bytes from the constant array to the heap array
	memmove( my_heap_array, my_initialized_2d_stack_array, 10 *sizeof(int) );

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//Can reuse the handler written previously
	c_style_stack_2d_handler_pointer( my_heap_array, 10, 5 );

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	cout << "Deallocate array" << endl;

	//Free the memory
	delete( my_heap_array );
	my_heap_array = NULL;

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function:


/****************************************************************************
**
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**
****************************************************************************/

void f( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function:


