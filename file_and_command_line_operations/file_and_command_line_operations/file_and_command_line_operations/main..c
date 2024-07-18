#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


typedef struct {
	int count;
	int ch;
}CHRCTR;

int compare_f(const void* v1, const void* v2)
{
	return ((const CHRCTR*)v2)->count - ((const CHRCTR*)v1)->count;
}


int main(int argc, char** argv)
{
	CHRCTR a[26];

	for (int i = 0; i < 26; ++i)
	{
		a[i].ch = 'A' + i;
		a[i].count = 0;
	}

	if (argc != 2)
	{
		fprintf(stderr, "the usage : <count_txt.exe> <the file name>\n");
		return 1;
	}

	FILE* f = fopen(argv[1], "r");

	if (!f)
	{
		fprintf(stderr, "the file can not opened...\n");
		return 2;

	}


	int ch;

	while ((ch = fgetc(f)) != EOF)
	{
		if (isalpha(ch))
			a[toupper(ch) - 'A'].count++;

	}

	qsort(a, 26, sizeof(*a), compare_f);


	for (int i = 0; i < 26; ++i)
		printf("%c : %d\n", a[i].ch, a[i].count);

	fclose(f);

	return 0;

}