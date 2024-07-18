#ifndef STUDENT_LIST
#define	STUDENT_LIST	

#include <stddef.h>


typedef struct Student Student;
typedef struct List List;
typedef List* ListHandle;




ListHandle create_list();
void destroy_list(ListHandle h);
void push_front(ListHandle h, const Student* ptr);
void pop_front(ListHandle h);
void get_first(ListHandle h, Student* ptr);
void print_list(ListHandle h);
size_t get_size(ListHandle h);
int is_empty(ListHandle h);
void make_empty(ListHandle h);









#endif