#include "nutility.h"
#include <stdlib.h>
#include <stdio.h>

#define		NAME_SIZE		10






const char* get_random_surname(void)
{

	static const char* surnames[NAME_SIZE] = {
	"MODALI", "ERBIL", "CALISKAN", "OZER", "ATES", "KIZILATES", "KASIKCI", "SUREL", "OZER", "YILDIRIM",
	};

	return surnames[rand() % asize(surnames)];


}

const char* get_random_name(void)
{

	static const char* names[NAME_SIZE] = {
		"AHMET", "MEHMET", "VELI", "KASIM", "TURABI", "SAID","MURAT","BURAK","MELIS", "SUDE",
	};
	return names[rand() % asize(names)];
}


int isprime(int x)
{
	if (x <= 1)
		return 0;
	else if (x % 2 == 0)
		return x == 2;
	else if (x % 3 == 0)
		return x == 3;
	else if (x % 5 == 0)
		return x == 5;
	else
		for (int i = 7; i < (x / 2 + 1); i += 2)
			if (x % i == 0)
				return 0;
	return 1;
}

void pline(void)
{
	printf("\n-----------------------------------------------------------------\n");
}

void set_array_random(int* p, size_t size)
{
	while (size--)
	{
		*p++ = rand() % 1000;

	}
}


void print_array(const int* p, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (i && i % 20 == 0)
			printf("\n");
		printf("%3d ", p[i]);

	}
	printf("\n-------------------------------------------------------------------\n");

}

void sgets(char* str)
{
	int ch;
	while ((ch = getchar()) != '\n')
		*str++ = ch;
	*str = '\0';
}


void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;

}

int* get_array_max(const int* ptr, size_t size)
{
	int* max_p = (int*)ptr;
	for (size_t i = 0; i < size; ++i)
		if (ptr[i] > *max_p)
			max_p = (int*)&ptr[i];
	return max_p;
}

int* get_array_min(const int* ptr, size_t size)
{
	int* min_p = (int*)ptr;
	for (size_t i = 0; i < size; ++i)
		if (ptr[i] < *min_p)
			min_p = (int*)&ptr[i];
	return min_p;
}

void selection_sort(int* ptr, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
		swap(get_array_min(ptr + i, size - i), ptr + i);

}


void base2_print(int val)
{
	static char ptr[40];
	_itoa(val, ptr, 2);
	printf("%032s\r", ptr);
}
