#include<stdio.h>
#define maxlines 1000
int getlines(char s[],int lim)
{
        int c,i,j;
        for (i = 0;i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++ )
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
void reverse(char s[],int len)
{
	int i;
	char t;	
	char newlines[maxlines];
	for(i=0;i<=len;i++)
	{
		printf("%c",s[len-i]);
        } 
}
int main()
{
	int len,i;
	char line[maxlines];
	while((len = getlines(line,maxlines)) > 0)
	{
			reverse(line,len);
	}
	return 0;
}
