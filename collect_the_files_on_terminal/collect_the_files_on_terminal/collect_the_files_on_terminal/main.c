
#include <stdio.h>



int main(int argc, char** argv)
{
	// the usage : <collected.exe>

	if (argc != 1)
	{
		fprintf(stderr, "the usage : <collect.exe>\n");
		return 1;

	}

	char file_name[40];
	FILE* fnew = fopen("collected.col", "wb");
	FILE* fold = NULL;

	int file_count = 0;
	int byte = 0;

	while (1)
	{
		sprintf(file_name, "divide%03d.div", file_count + 1);
		fold = fopen(file_name, "rb");
		if (!fold)
			break;
		else
		{
			int ch;
			while ((ch = fgetc(fold)) != EOF)
			{
				fputc(ch, fnew);
				byte++;

			}
			file_count++;
		}
		fclose(fold);
		if (remove(file_name))
		{
			printf("the file can not be cleaned...\n");
			return 2;
		}
		fold = NULL;

	}
	fclose(fnew);
	printf("the %d file is collected [%d byte] and new file_name collected.col\n", file_count, byte);
	return 0;

}