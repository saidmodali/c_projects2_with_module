#include <stdio.h>
#include "main.h"


int i_cmp(const void* ptr1, const void* ptr2)
{
	if (*(const int*)ptr1 > *(const int*)ptr2)
		return 1;
	return -1;

}




void generic_swap(void* ptr1, void* ptr2, size_t sz)
{
	char* c_ptr1 = (char*)ptr1;
	char* c_ptr2 = (char*)ptr2;

	while (sz--)
	{
		char temp = *c_ptr1; //(precaution : must number no adress!!!)
		*c_ptr1++ = *c_ptr2;
		*c_ptr2++ = temp;
	}


}



void my_qsort(void* ptr, size_t size, size_t sz, int (*fp)(const void*, const void*))
{
	char* c_ptr = (char*)ptr;
	for (size_t i = 0; i < size; ++i)
		for (size_t k = 0; k < size - 1 ; ++k)
			if (fp(c_ptr + k * sz, c_ptr + (k + 1) * sz ) > 0)
			{
				generic_swap(c_ptr + k * sz, c_ptr + (k + 1) * sz , sz);

			}
}


