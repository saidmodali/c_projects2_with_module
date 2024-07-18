#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define		SIZE					100


char* create_random_password(void)
{
	static char ptr[SIZE]; // static keywords using...

	size_t len = rand() % 20 + 1;
	size_t i = 0;
	for (; i < len; ++i)
		ptr[i] = rand() % 49 + rand() % 76;
	ptr[i] = '\0';

	return ptr;

}




int main()
{
	char* ptr;
	int ch = '\n';
	srand((unsigned)time(NULL)); //to get new values at the next working time...

	while (1)
	{
		if (ch == ' ')
			break;
		ptr = create_random_password();
		printf("your new password : %s\n(enter space to end before enter)", ptr);
		ch = getchar();
	}

	return 0;
}