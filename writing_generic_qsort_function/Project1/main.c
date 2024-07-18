/*

author : said modali

that's code was written to understand how to work generic functions and the standard qsort function...

*/

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define		SIZE				5





int main()
{
	int a[SIZE] = { 5,4,3,2,1 };
	
	for (int i = 0; i < SIZE; ++i)
		printf("%d ", a[i]);

	putchar('\n');

	my_qsort(a, SIZE, sizeof(int), i_cmp);

	for (int i = 0; i < SIZE; ++i)
		printf("%d ", a[i]);


	return 0;



}