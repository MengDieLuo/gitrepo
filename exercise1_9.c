#include <stdio.h>
int main()
{
	int c,pc;
	pc = EOF;
	while ((c = getchar()) != EOF)
	{
		if (c != ' ')
		{
			putchar(c);
		}
		if (c != ' ')
		{
			putchar(c);
		}
		pc = c;
	}
	return 0;
}


