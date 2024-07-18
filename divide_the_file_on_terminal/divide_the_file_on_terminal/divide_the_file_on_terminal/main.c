#include <stdio.h>
#include <stdlib.h>




int main(int argc, char** argv)
{
	char filename[50];

	if (argc != 3)
	{
		fprintf(stderr, "the usage : <divide.exe> <the filename> <bytes>");
		return 1;

	}

	FILE* fsource = fopen(argv[1], "rb");

	if (!fsource)
	{
		fprintf(stderr, "the source file can not be opened...\n");
		return 2;

	}

	int ch;
	int file_count = 0;
	int byte = 0;
	int chunk = atoi(argv[2]);

	FILE* fdest = NULL;

	while ((ch = fgetc(fsource)) != EOF)
	{
		if (!fdest)
		{
			sprintf(filename, "divide%03d.div", file_count + 1);
			fdest = fopen(filename, "wb");
			if (!fdest)
			{
				fprintf(stderr, "the file can not occured...\n");
				return 3;

			}
			file_count++;
		}
		fputc(ch, fdest);
		byte++;

		if (byte % chunk == 0)
		{
			fclose(fdest);
			fdest = NULL;
			byte = 0;

		}

	}
	fclose(fsource);
	if (fdest)
	{
		fclose(fdest);
	}

	printf("The file named %s, which is %d bytes in size, has been split into %d parts successfully.\n", argv[1], chunk, file_count);

	return  0;



}