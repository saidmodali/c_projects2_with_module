#include <stdio.h>
#include "nutility.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>





int main(void)
{
	int x = 0;
	for (;;)
	{
		while (x != -1)
		{
			x |= (1 << (rand() % 32));
			base2_print(x);
			Sleep(10);

		}
		printf("all bits are 1\n");
		Sleep(500);

		while (x)
		{
			x &= ~(1 << (rand() % 32));
			base2_print(x);
			Sleep(10);
		}
		printf("all bits are 0\n");
		Sleep(500);
	}
	return 0;


}