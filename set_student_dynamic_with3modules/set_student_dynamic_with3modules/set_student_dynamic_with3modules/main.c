#include <stdio.h>
#include "nutility.h"
#include "student.h"
#include "student_list.h"
#include <stdlib.h>
#include <time.h>





int main(void)
{
	size_t n;
	Student s;
	printf("how many student will be add in the list ? :");
	scanf("%zu", &n);
	for (size_t i = 0; i < n; ++i)
	{
		set_student_random(&s);
		push_front(&s);
	}


	while (!is_empty())
	{
		printf("\n--------------------------------------------\n");
		printf("\nthere are %zu student in the list.....\n", get_size());
		print_list();
		getchar();
		system("cls");
		pop_front();

	}




}