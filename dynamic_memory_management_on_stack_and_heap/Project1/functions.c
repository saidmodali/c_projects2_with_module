#include "main.h"



void m_array_init(int** ptr, size_t row, size_t column)
{
	for (size_t i = 0; i < row; ++i)
		for (size_t k = 0; k < column; ++k)
			ptr[i][k] = rand() % 6;

}

void m_array_print(int** ptr, size_t row, size_t column)
{
	for (size_t i = 0; i < row; ++i)
	{
		for (size_t k = 0; k < column; ++k)
		{
			printf("%d ", ptr[i][k]);
		}
		putchar('\n');
	}

}