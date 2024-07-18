#include "main.h"

/*


That's code was written by said modali
the purpose is that how to do multi-dimensional array with automatic storage class(on stack) or dynamic storage class(on heap)....

*/

int main(void)
{
	printf("the array with automatic storage class(ON STACK)\n");


	int a[5][5] =             /// ON STACK MULTI D. ARRAY ....
	{
		[0] = {0, 1, 2, 3, 4},
		[1] = { 5, 6, 7, 8, 9 }
	};

	int* ptr_a = a[0];

	for (int i = 0; i < 25; ++i)
	{
		printf("%d ", *(ptr_a + i));
		if ((i + 1) % 5 == 0)
			putchar('\n');
	}

	printf("\n\n\n");



	printf("the dynamic array (on heap)\n");

	size_t row, column;           /// ON HEAP MULTI D. ARRAY....
	printf("enter row : ");
	scanf("%zu", &row);
	printf("enter column : ");
	scanf("%zu", &column);

	int** ptr = (int**)malloc(row * sizeof(int*));// allocate for row

	if (!ptr)
		exit(EXIT_FAILURE); // test: is available the memory ? 

	for (size_t i = 0; i < row; ++i)
	{
		ptr[i] = (int*)malloc(column * sizeof(int));//allocate for col

		if (!ptr[i]) //test: is a available the memory ? 
			exit(EXIT_FAILURE);
	}

	srand((unsigned)time(NULL)); //for random



	m_array_init(ptr, row, column);
	m_array_print(ptr, row, column);

	for (size_t i = 0; i < row; ++i)// set to free
		free(ptr[i]);

	free(ptr); // set to free
	ptr = NULL;  // now, invalid....

	putchar('\n');
	printf("it is done successfully....");
	return 0;







}