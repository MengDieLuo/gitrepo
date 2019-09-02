#include <stdio.h>
int main()
{
	int d,c;
	d = 0;
	while ((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\t' || c == '\n')
    		{
			if (d == 0)
			{
				d = 1;
				putchar('\n');
			}
		}
		else
		{
			d = 0;
			putchar(c);
		}
	}
	return 0;
}
