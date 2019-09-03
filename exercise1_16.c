#include <stdio.h>
#define maxlines  1000
int getlines(char line[], int maxline);
void copy(char to[], char from[]);
int main()
{
	int len;
	int max;
	char line[maxlines];
	char longest[maxlines];
	max = 0;
	while((len = getlines(line,maxlines)) > 0)
	{
		printf("%d: %s",len,line);
		if(len > max)
		{
			max = len;
			copy(longest,line);
		}
	}
	if(max > 0)
	{
		printf("Longest is %d characters:\n%s",max,longest);
	}
	printf("\n");
	return 0;
}
int getlines(char s[],int lim)
{
	int c,i,j;
	for (i = 0,j = 0; (c = getchar())!= EOF&&c!='\n'; i++ )
	{
		if(i < lim-1)
			s[j++]=c;
	}
	if(c == '\n')
	{
		if(i < lim-1)
			s[j++] = c;
		i++;
	}
	s[j] = '\0';
	return i;
}
void copy(char to[],char from[])
{
	int i=0; 
	while((to[i] = from[i]) != '\0')
		i++;
}
