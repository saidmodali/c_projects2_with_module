#include <stdio.h>
#include <stdlib.h>





int main(int argc, char** argv)
{

	// the usage : <encrypt.exe> <file_name> <code : (be carefull do not forget!)>

	if (argc != 3)
	{
		fprintf(stderr, " the usage : <encrypt.exe> <file_name> <code : (be carefull do not forget!)>\n");
		return 1;

	}

	FILE* fold = fopen(argv[1], "rb");
	if (!fold)
	{
		fprintf(stderr, "your file can not be opened...\n");
		return 2;

	}
	const char* new_file_name = tmpnam(NULL);
	FILE* fnew = fopen(new_file_name, "wb");
	if (!fnew)
	{
		fprintf(stderr, "new file can not be occured...\n");
		return 3;

	}
	unsigned seed_val = atoi(argv[2]);
	srand(seed_val);

	int ch;
	while ((ch = fgetc(fold)) != EOF)
		fputc(ch ^ rand(), fnew);

	fclose(fold);
	if (remove(argv[1]))
	{
		fprintf(stderr, "the %s file can not removed...\n", argv[1]);
		return 4;

	}
	fclose(fnew);
	if (rename(new_file_name, argv[1]))
	{
		fprintf(stderr, "the can not renamed the file...\n");
		return 5;
	}

	printf("the file ecrypted....\n");

	return 0;

}