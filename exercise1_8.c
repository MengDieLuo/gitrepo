#include <stdio.h>
int main()
{
	int blank,tabs,newlines;
	blank = 0;
	tabs = 0;
	newlines = 0;
	int c;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			blank++;
		}
		if (c == '\t')
		{
			tabs++;
		}
		if (c == '\n')
		{
			newlines++;
		}
	}
	printf("Blanks: %d\nTabs: %d\nLines: %d\n", blank, tabs, newlines);
	return 0;
}
