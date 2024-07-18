#include <stdio.h>
#include <time.h>
#include <stdlib.h>



#define				SIZE			20

int is_function(const void* x, const void* y)
{
	const int* ptr_x = (const char*)x;
	const int* ptr_y = (const char*)y;
	return *ptr_x - *ptr_y;


}

void print_array(const int* ptr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (i % 10 == 0)
			printf("\n");
		printf("%d ", *(ptr + i));
	}
	printf("\n-------------------------------------------------------------------\n");

}

int main(void)
{
	int a[SIZE] = { 10,20,30,40,50,60,70,80,90,100,5,10,15,25,35,45,55,65,75,85 };

	clock_t start = clock();
	print_array(a, SIZE);
	qsort(a, SIZE, sizeof(int), is_function);
	print_array(a, SIZE);
	clock_t end = clock();
	printf("the total time for process : %f", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;



}