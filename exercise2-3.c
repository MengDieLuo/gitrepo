#include <stdio.h>
#define maxlines 100
#define YES 1
#define NO 0
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
int htoi(char s[])
{
	int hexdigit,i,inhex,n;
	i=0;
	if(s[i] == '0')
	{
		i++;
		if(s[i] == 'x' || s[i] == 'X')
		{
			i++;
		}
	}
	n=0;
	inhex=YES;
	while(inhex == YES)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			hexdigit = s[i] - '0';
		}
		else if(s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else
			inhex=NO;
		if(inhex == YES)
		{
			n = 16 * n + hexdigit;
		}
		i++;
	}
	return n;
}
int main()
{
	char s[maxlines];
	int value;
	getlines(s,maxlines);
	value=htoi(s);
	printf("The value of %s is %d",s,value);
	return 0;
}
