#ifndef		MDLI
#define		MDLI


#include "date.h"
#include <stdlib.h>
#include <string.h>
#include "nutility.h"




typedef struct Student {
	int no;
	char name[20];
	char surname[20];
	Date bhirt_Day;

}Student;

void set_student_random(Student* ptr);
void print_student(Student* ptr);











#endif