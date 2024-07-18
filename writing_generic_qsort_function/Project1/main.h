

#ifndef MDLI
#define	MDLI



#include <stdio.h>


void my_qsort(void* ptr, size_t size, size_t sz, int (*fp)(const void*, const void*));
int i_cmp(const void* ptr1, const void* ptr2);
void generic_swap(void* ptr1, void* ptr2, size_t sz);















#endif
