#include <stdio.h>
#define MINLENGTH 81
int getlines(char line[])
{
	int i=0;
	int c;
	while (i < MINLENGTH)
	{
		c = getchar();
		if (c == EOF)
			return -1;
		if (c == '\n') 
			return 0;
		line[i++] = c;
	}
	return 1;
}
int copy(char line[])
{
	int i,c,status=1;
	for(i=0; i<MINLENGTH; i++)
	{
		putchar(line[i]);
	}
	while(status == 1)
	{
		c = getchar();
		if (c == EOF)
			status=-1;
		else if (c == '\n')
			status=0;
		else
			putchar(c);
	}
	putchar('\n');
	return status;
}
int main()
{
	char line[MINLENGTH];
	int status = 0;
	while(status != -1)
	{
		status = getlines(line);
		if (status == 1)
			status = copy(line);
	}
	return 0;
}
