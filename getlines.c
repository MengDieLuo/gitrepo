#include <stdio.h>
int getlines(char line[], int maxline);
void copy(char to[], char from[]);
int main()
{
	int len;
	int max;
	char line[1000];
	char longest[1000];
	max = 0;
	while((len = getlines(line,1000)) > 0)
		if(len > max)
		{
			max = len;
			copy(longest,line);
		}
	if(max > 0)
	{
		printf("%s",longest);
	}
	return 0;
}
int getlines(char s[],int lim)
{
        int c,i;
        for (i = 0; i < lim - 1&&(c = getchar()) != EOF && c != '\n'; i++ )
        {
                s[i]=c;
        }
        if(c == '\n')
        {
                s[i] = c;
                i++;
        }
        s[i] = '\0';
        return i;
}
void copy(char to[],char from[])
{
        int i=0;
        while((to[i] = from[i]) != '\0')
        i++;
}
