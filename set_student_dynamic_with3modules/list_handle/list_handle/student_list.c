#include "student_list.h"
#include "student.h"
#include <stdlib.h>



typedef struct Node {
	Student s;
	struct Node* pnext;
}Node;

typedef struct List {
	Node* gpfirst;
	size_t gcount;

}List, * ListHandle;





ListHandle create_list()
{
	ListHandle h = (ListHandle)malloc(sizeof(List));


	if (!h)
	{
		printf("memory not available....");
		exit(EXIT_FAILURE);
	}
	h->gpfirst = NULL;
	h->gcount = 0;

	return h;




}


void destroy_list(ListHandle h)
{
	make_empty(h);
	free(h);
}



void push_front(ListHandle h, const Student* ptr)
{
	Node* pnew = (Node*)malloc(sizeof(Node));
	if (!pnew)
	{
		printf("memory not available...");
		exit(EXIT_FAILURE);

	}
	pnew->s = *ptr;
	pnew->pnext = h->gpfirst;
	h->gpfirst = pnew;
	++(h->gcount);


};


void pop_front(ListHandle h)
{


	if (is_empty(h))
	{
		printf("already the list empty...");
		exit(EXIT_FAILURE);
	}
	Node* delptr = h->gpfirst;
	h->gpfirst = h->gpfirst->pnext;
	free(delptr);
	--(h->gcount);



}


void get_first(ListHandle h, Student* ptr)
{
	if (is_empty(h))
	{
		printf("the list empty.....");
		exit(EXIT_FAILURE);
	}
	*ptr = h->gpfirst->s;
}



void print_list(ListHandle h)
{
	for (Node* p = h->gpfirst; p != NULL; p = p->pnext)
	{
		print_student(&p->s);
	}
	printf("-----------------------------------------\n");

}


size_t get_size(ListHandle h)
{
	return h->gcount;
}


int is_empty(ListHandle h)
{
	return h->gpfirst == NULL;
};



void make_empty(ListHandle h)
{
	while (!is_empty(h))
		pop_front(h);


};




