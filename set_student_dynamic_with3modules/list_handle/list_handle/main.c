#include <stdio.h>
#include "nutility.h"
#include "student.h"
#include "student_list.h"
#include <stdlib.h>
#include <time.h>


#define		NLIST			100



int main(void)
{
	ListHandle the_list[NLIST];
	Student s;

	for (int i = 0; i < NLIST; ++i)
	{
		the_list[i] = create_list(); //it is done l1, l2, l3..., lNLIST
		for (int j = 0; j < NLIST; ++j)
		{
			set_student_random(&s);
			push_front(the_list[i], &s);


		}

	}


	for (int i = 0; i < NLIST; ++i)
	{
		printf("%d. list : \n", i);
		print_list(the_list[i]);
		(void)getchar();
		system("cls");

	}

	for (int i = 0; i < NLIST; ++i)
		destroy_list(the_list[i]);
	return 0;





}