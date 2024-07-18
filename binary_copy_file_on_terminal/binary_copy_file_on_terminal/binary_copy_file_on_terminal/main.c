#include <stdio.h>




int main(int argc, char** argv)
{
	//the usage : <copy.exe> <source file> <destination file>

	if (argc != 3)
	{
		fprintf(stderr, "the usage : <copy.exe> <source file> <destination file>\n");
		return 1;

	}

	FILE* f_s, * f_d;
	f_s = fopen(argv[1], "rb");
	f_d = fopen(argv[2], "wb");

	if (!f_s)
	{
		fprintf(stderr, "the source file can not be opened...\n");
		return 2;
		fclose(f_d);
	}

	if (!f_d)
	{
		fprintf(stderr, "the destination file opening failure...\n");
		fclose(f_s);
		return 3;

	}
	int ch;
	int byte_count = 0;

	while ((ch = fgetc(f_s)) != EOF)
	{
		byte_count++;
		fputc(ch, f_d);
	}

	printf("%s is copied %s successfully...(%d byte)\n", argv[1], argv[2], byte_count);

	fclose(f_s);
	fclose(f_d);
	return 0;



}