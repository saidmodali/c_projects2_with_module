#ifndef VECTOR_H
#define	VECTOR_H


#include <stddef.h>
#include <stdbool.h>

#define		NOT_FOUND			((size_t)-1)
#define		DEFAULT_CAPACITY		(12)

typedef int DATATYPE;

typedef struct tagVector {
	DATATYPE* mptr;
	DATATYPE msize;
	DATATYPE mcap;

}Vector, * Hvector;

Hvector create_vector(void);
Hvector create_vector_with_capacity(size_t cap);
Hvector create_vector_with_array(const DATATYPE* ptr, size_t size);
Hvector create_fiilled_vector(size_t size, DATATYPE val);
Hvector destroy_vector(Hvector handle);
void print_handle(Hvector h);


bool set_capacity(Hvector handle, size_t newcap);
bool push_back(Hvector handle, size_t val);
bool pop_back(Hvector handle);
bool insert(Hvector handle, size_t idx, DATATYPE val);




//functional macros:
#define get_size(hvec)            ((hvec)->msize)
#define get_capacity(hvec)		  ((hvec)->mcap) 
#define get_item(hvec, idx)		  (((hvec)->mp)[idx])








#endif