#include "student_list.h"
#include "student.h"
#include <stdlib.h>



typedef struct Node {
	Student s;
	struct Node* pnext;
}Node;

static Node* gpfirst = NULL;
static size_t gcount = 0;


void push_front(const Student* ptr)
{
	Node* pnew = (Node*)malloc(sizeof(Node));
	if (!pnew)
	{
		printf("memory not available...");
		exit(EXIT_FAILURE);

	}
	pnew->s = *ptr;
	pnew->pnext = gpfirst;
	gpfirst = pnew;
	++gcount;


};


void pop_front(void)
{
	if (is_empty())
	{
		printf("already the list empty...");
		exit(EXIT_FAILURE);
	}
	Node* delptr = gpfirst;
	gpfirst = gpfirst->pnext;
	free(delptr);
	--gcount;



}


void get_first(Student* ptr)
{
	if (is_empty())
	{
		printf("the list empty.....");
		exit(EXIT_FAILURE);
	}
	*ptr = gpfirst->s;
}



void print_list(void)
{
	for (Node* p = gpfirst; p != NULL; p = p->pnext)
	{
		print_student(&p->s);
	}
	printf("-----------------------------------------\n");

}


size_t get_size(void)
{
	return gcount;
}


int is_empty(void)
{
	return gpfirst == NULL;
};



void make_empty(void)
{
	while (!is_empty())
		pop_front();


};





