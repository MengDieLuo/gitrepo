#include<stdio.h>
#define maxlines 1000
int getlines(char s[],int lim)
{
	int c,i,j;
	for (i = 0;i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i )
	{
		s[i]=c;
	}
	if(c == '\n')
	{
	
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
int main()
{
	int len,i;
	char line[maxlines];
	while((len=getlines(line,maxlines))>0)
	{
		i=len-2;
        	for(i>=0;((line[i]==' ')||(line[i]=='\t'));--i)
        	        ;
        	if(i>=0)
        	{
                	line[i+1] = '\n';
                	
                	line[i+2] = '\0';
                	printf("%s",line);
        	}	
	}
	return 0;
}
