#ifndef STUDENT_LIST
#define	STUDENT_LIST	

#include <stddef.h>


struct Student;
typedef struct Student Student;


void push_front(const Student* ptr);
void pop_front(void);
void get_first(Student* ptr);
void print_list(void);
size_t get_size(void);
int is_empty(void);
void make_empty(void);









#endif