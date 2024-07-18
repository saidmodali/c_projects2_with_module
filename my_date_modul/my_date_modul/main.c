#include <stdio.h>
#include "date.h"
#include <stdlib.h>




int main(void)
{
	size_t n;
	Date* ptr;
	printf("please enter how many dates you want :  ");
	scanf("%zu", &n);

	ptr = (Date*)malloc(n * sizeof(Date));

	if (!ptr)
	{
		printf("memory is not available...");
		abort();
	}
	srand((unsigned)time(NULL));
	set_date_array(ptr, n);
	print_date_array(ptr, n);
	free(ptr);


	
}