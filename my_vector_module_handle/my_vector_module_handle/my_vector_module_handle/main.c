#include <stdio.h>
#include "vector.h"

/*
this code written by muhammed said modali.

This code defines and implements a dynamic array (vector) in C.
It includes functions to create, destroy, and manipulate the vector, including adding, inserting,
and removing elements, as well as printing the vector's details.
The vector's capacity is dynamically adjusted as needed to accommodate new elements.

ALL RIGHTS RESERVED...

*/




int main(void)  // the test code...
{
	Hvector handle = create_fiilled_vector(100, 100);
	print_handle(handle);

	for (int i = 0; i < 100; ++i)
		push_back(handle, 20);

	print_handle(handle);

	set_capacity(handle, 500);

	insert(handle, 4, 1996);
	print_handle(handle);
	destroy_vector(handle);
	return 0;







}