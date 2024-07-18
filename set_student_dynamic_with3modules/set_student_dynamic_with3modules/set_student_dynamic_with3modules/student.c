#include "student.h"


#define		PUBLIC
#define		PRIVATE			static






PUBLIC void set_student_random(Student* ptr)
{
	ptr->no = rand() % 2000 + 1;
	strcpy(ptr->name, get_random_name());
	strcpy(ptr->surname, get_random_surname());
	set_date_random(&(ptr->bhirt_Day));

};


PUBLIC void print_student(Student* ptr)
{
	printf("%s ", ptr->name);
	printf("%d ", ptr->no);
	printf("%s ", ptr->surname);
	print_date(&(ptr->bhirt_Day));
	printf("\n");



}
