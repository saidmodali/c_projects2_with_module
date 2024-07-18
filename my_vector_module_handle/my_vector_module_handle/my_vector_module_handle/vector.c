#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>






Hvector create_vector(void) // it sets default capacity...
{
	return create_vector_with_capacity(DEFAULT_CAPACITY);
}





Hvector create_vector_with_capacity(size_t cap) // it sets according to capacity...
{
	Hvector h = (Hvector)malloc(cap * sizeof(Vector));
	if (!h)
	{
		printf("memory not available...\n");
		return NULL;
	}

	h->msize = 0;
	h->mcap = (size_t)cap;

	h->mptr = (DATATYPE*)malloc(cap * sizeof(DATATYPE));
	if (!(h->mptr))
	{
		free(h);
		printf("memory not available...\n");
		return NULL;
	}

	return h;

}



Hvector create_vector_with_array(const DATATYPE* ptr, size_t size)
{
	Hvector h = create_vector_with_capacity(size);
	if (!h)
		if (!h)
		{
			printf("memory not available...\n");
			return NULL;
		}
	memmove(h->mptr, ptr, sizeof(DATATYPE) * size);
	h->msize = size;

	return h;

}



Hvector create_fiilled_vector(size_t size, DATATYPE val)
{
	Hvector h = create_vector_with_capacity(size);
	if (!h)
	{
		printf("memory not available...\n");
		return NULL;
	}

	h->msize = size;

	for (size_t i = 0; i < size; ++i)
		(h->mptr)[i] = val;

	return h;


}

Hvector destroy_vector(Hvector handle)
{
	free(handle->mptr);
	free(handle);
}



bool set_capacity(Hvector handle, size_t newcap)
{
	if (newcap < handle->mcap)
		return false;
	else if (newcap == handle->mcap)
		return true;

	DATATYPE* ptr_new = (DATATYPE*)realloc(handle->mptr, sizeof(DATATYPE) * newcap);

	if (!ptr_new)
	{
		printf("memory not available...\n");
		return false;
	}

	handle->mcap = newcap;
	handle->mptr = ptr_new;
	return true;

}


bool push_back(Hvector handle, size_t val)
{
	if (handle->msize == handle->mcap && !set_capacity(handle, (handle->mcap) * 2))
		return false;

	(handle->mptr)[handle->msize] = val;
	handle->msize++;
	return true;

}


bool insert(Hvector handle, size_t idx, DATATYPE val)
{
	if (idx > handle->msize)
		return false;

	if (handle->msize == handle->mcap && !set_capacity(handle, (handle->mcap) * 2))
		return false;

	// 1   2 3 4 5 

	memmove(handle->mptr + idx + 1, handle->mptr + idx, (handle->msize - 1) * sizeof(DATATYPE));
	(handle->mptr)[idx] = val;
	++handle->msize;

	return true;

}


bool pop_back(Hvector handle)
{
	if (!(handle->msize))
		return false;

	handle->msize--;
	return true;

}


void print_handle(Hvector h)
{
	printf("the capacity : %zu, the size : %zu and the elements : \n", get_capacity(h), get_size(h));

	for (size_t i = 0; i < (h->msize); ++i)
	{
		if (i && i % 10 == 0)
			putchar('\n');

		printf("%0.2d ", (h->mptr)[i]);
	}
	putchar('\n');




}