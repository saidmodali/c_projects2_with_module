#include <stdio.h>
#include <stdlib.h>


int main()
{
	int ch;
	int cnt = 0;
	int x;
	int* ptr = NULL;

	while (1)
	{

		printf("are you sure to enter a number ? : ");

		while ((ch = getchar()) == 'e' && ch != 'h')
		{
			scanf("%d", &x);
			++cnt;
			ptr = (int*)realloc(ptr, cnt * sizeof(int));
			ptr[cnt - 1] = x;

			if (!ptr)
			{
				printf("it is not available the memory...\n");
				exit(EXIT_FAILURE);
			}



		}

		if (ch == 'h')
			break;
	}

	if (ptr)
	{
		for (int i = 0; i < cnt; ++i)
			printf("%d ", ptr[i]);
	}

	free(ptr);
	return 0;

}