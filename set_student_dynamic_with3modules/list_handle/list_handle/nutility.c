#include "nutility.h"
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




//
//#include "nutility.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//
//
//#define SIZE			100	
//
//f1(void)
//{
//	printf("f1 is called...\n");
//
//}
//
//f2(void)
//{
//	printf("f2 is called...\n");
//
//
//}
//
//f3(void)
//{
//	printf("f3 is called...\n");
//
//}
//
//int main(void)
//{
//	atexit(f1);
//	exit(EXIT_SUCCESS);
//	atexit(f2);
//	atexit(f3);
//	//abort();
//
//
//	return 0;
//
//}


//
//#include "nutility.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//
//int main(void)
//{
//	printf("how many will you have elemnts of your array? : ");
//	size_t n;
//	scanf("%zu", &n);
//
//	int* ptr = (int*)malloc(n * sizeof(int));
//
//	if (!ptr)
//		exit(EXIT_FAILURE);
//
//	srand((unsigned)time(NULL));
//	set_array_random(ptr, n);
//	print_array(ptr, n);
//	free(ptr);
//	return 0;
//
//
//}

//
//
//#include "nutility.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <string.h>
//
//#define SIZE			5
//
//int compare(const void* ptr1, const void* ptr2)
//{
//	return *(const int*)ptr1 - *(const int*)ptr2;
//
//}
//
//int get_mean(const int* ptr, size_t size)
//{
//	int* copy_ptr = (int*)malloc(size * sizeof(int));
//	if (!copy_ptr)
//	{
//		printf("memory are is not available");
//		exit(EXIT_FAILURE);
//	}
//	memcpy(copy_ptr, ptr, size * sizeof(int));
//	qsort(copy_ptr, size, sizeof(int), compare); //it is sorted
//	int mean_val = copy_ptr[size / 2];
//	free(copy_ptr);
//	return mean_val;
//}
//
//int main(void)
//{
//	int ptr[SIZE];
//
//	set_array_random(ptr, SIZE);
//	print_array(ptr, 5);
//	int mean_v = get_mean(ptr, SIZE);
//	printf("the mean value : %d", mean_v);
//	return 0;
//
//
//}

//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define SIZE			40
//
//char* get_dynamic_total(const char* s1, const char* s2)
//{
//	char* pt = (char*)malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
//	if (!pt)
//	{
//		printf("memory not available...");
//		exit(EXIT_FAILURE);
//	}
//	strcpy(pt, s1);
//	strcat(pt, s2);
//	return pt;
//}
//
//int main(void)
//{
//	char s1[40];
//	char s2[40];
//	printf("enter a sentence (1): ");
//	scanf("%s", s1);
//	printf("enter a sentence (2): ");
//	scanf("%s", s2);
//	char* p = get_dynamic_total(s1, s2);
//	puts(p);
//	free(p);
//	return 0;
//}

//
//#include "nutility.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void m_array_init(int** ptr, size_t row, size_t column)
//{
//	for (size_t i = 0; i < row; ++i)
//		for (size_t k = 0; k < column; ++k)
//			ptr[i][k] = rand() % 6;
//
//}
//
//void m_array_print(int** ptr, size_t row, size_t column)
//{
//	for (size_t i = 0; i < row; ++i)
//	{
//		for (size_t k = 0; k < column; ++k)
//		{
//			printf("%d ", ptr[i][k]);
//		}
//		putchar('\n');
//	}
//
//}
//
//int main(void)
//{
//	printf("the array with automatic storage class(ON STACK)\n");
//
//
//	int a[5][5] =             /// ON STACK MULTI D. ARRAY ....
//	{
//		[0] = {0, 1, 2, 3, 4},
//		[1] = { 5, 6, 7, 8, 9 }
//	};
//
//	int* ptr_a = a[0];
//
//	for (int i = 0; i < 25; ++i)
//	{
//		printf("%d ", *(ptr_a + i));
//		if ((i + 1) % 5 == 0)
//			putchar('\n');
//	}
//
//	printf("\n\n\n");
//
//
//
//	printf("the dynamic array (on heap)\n");
//
//	size_t row, column;           /// ON HEAP MULTI D. ARRAY....
//	printf("enter row : ");
//	scanf("%zu", &row);
//	printf("enter column : ");
//	scanf("%zu", &column);
//
//	int** ptr = (int**)malloc(row * sizeof(int*));// allocate for row
//
//	if (!ptr)
//		exit(EXIT_FAILURE); // test: is available the memory ? 
//
//	for (size_t i = 0; i < row; ++i)
//	{
//		ptr[i] = (int*)malloc(column * sizeof(int));//allocate for col
//
//		if (!ptr[i]) //test: is a available the memory ? 
//			exit(EXIT_FAILURE);
//	}
//
//	srand((unsigned)time(NULL)); //for random
//
//
//
//	m_array_init(ptr, row, column);
//	m_array_print(ptr, row, column);
//
//	for (size_t i = 0; i < row; ++i)// set to free
//		free(ptr[i]);
//
//	free(ptr); // set to free
//	ptr = NULL;  // now, invalid....
//
//	putchar('\n');
//	printf("it is done successfully....");
//	return 0;
//
//
//
//
//
//
//
//}
//
//
//#include <stdio.h>
//#include "nutility.h"
//#include <stdlib.h>
//
//
//
//
//int main()
//{
//	int* ptr = (int*)calloc(5, sizeof(int));
//
//	if (!ptr)
//	{
//		printf("memory is not available...");
//		exit(EXIT_FAILURE);
//
//	}
//
//
//	for (int i = 0; i < 5; ++i)
//		printf("%d ", ptr[i]);
//
//	free(ptr);
//
//	return 0;
//
//
//
//}
//#include <stdio.h>
//#include "nutility.h"
//#include <stdlib.h>
//
//
//// hit : reallocation reduces efficiency....
//
//
//int main()
//{
//	size_t n, add_n;
//	printf("enter size of your array : ");
//	scanf("%zu", &n);
//
//	int* ptr = (int*)malloc(n * sizeof(int));
//	if (!ptr)
//	{
//		printf("memory not available...");
//		exit(EXIT_FAILURE);
//	}
//	srand((unsigned)(time(NULL)));
//
//	set_array_random(ptr, n);
//	printf("\np = %p\n", ptr);
//	print_array(ptr, n);
//
//	printf("enter new size : ");
//	scanf("%zu", &add_n);
//	add_n = add_n - n;
//
//	ptr = (int*)realloc(ptr, (n + add_n) * sizeof(int));
//	if (!ptr)
//	{
//		printf("memory not available...");
//		exit(EXIT_FAILURE);
//
//	}
//
//	set_array_random(ptr + n, add_n);
//	print_array(ptr, n + add_n);
//	printf("p = %p", ptr); // it can change or not unspecified behaviour.
//	free(ptr);
//
//
//	return 0;
//
//
//
//}

//
//#include <stdio.h>
//#include "nutility.h"
//#include <stdlib.h>
//
//
//int main()
//{
//	int ch;
//	int cnt = 0;
//	int x;
//	int* ptr = NULL;
//
//	while (1)
//	{
//
//		printf("are you sure to enter a number ? : ");
//
//		while ((ch = getchar()) == 'e' && ch != 'h')
//		{
//			scanf("%d", &x);
//			++cnt;
//			ptr = (int*)realloc(ptr, cnt * sizeof(int));
//			ptr[cnt - 1] = x;
//
//			if (!ptr)
//			{
//				printf("it is not available the memory...\n");
//				exit(EXIT_FAILURE);
//			}
//
//
//
//		}
//
//		if (ch == 'h')
//			break;
//	}
//
//	if (ptr)
//		print_array(ptr, cnt);
//	free(ptr);
//	return 0;
//
//}

//time.h using 
//#include <stdio.h>
//#include "nutility.h"
//#include <time.h>
//
//#define				SIZE		100
//
//int main(void)
//{
//	char str[SIZE];
//	time_t timer = time(NULL);
//	struct time* ptimer = localtime(&timer);
//	strftime(str, SIZE, "THE DATE : %A %B %Y", ptimer);
//	puts(str);
//	return 0;
//
//}

// calculate the process time  : 
//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//
//
//
//#define				SIZE			20
//
//int is_function(const void* x, const void* y)
//{
//	const int* ptr_x = (const char*)x;
//	const int* ptr_y = (const char*)y;
//	return *ptr_x - *ptr_y;
//
//
//}
//
//int main(void)
//{
//	int a[SIZE] = { 10,20,30,40,50,60,70,80,90,100,5,10,15,25,35,45,55,65,75,85 };
//
//	clock_t start = clock();
//	print_array(a, SIZE);
//	qsort(a, SIZE, sizeof(int), is_function);
//	print_array(a, SIZE);
//	clock_t end = clock();
//	printf("the total time for process : %f", (double)(end - start) / CLOCKS_PER_SEC);
//	return 0;
//
//
//
//}

