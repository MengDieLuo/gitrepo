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
	int t,len;
	int nl,ns;
	int maxlong=10;
	char line[maxlines];
	char buf[maxlines];
	while((len = getlines(line,maxlines))>0) 
	{
		if(len<maxlong)
			;
		else
		{
			t=0;
			nl=0;
			while(t<len)
			{
				if(line[t] == ' ')
				{
					ns = t;
				}
				if(nl == maxlong)
				{
					line[ns] = '\n';
					nl = 0;
				}
				nl++;
				t++;
			}
		}
		printf("%s",line);
	}
	return 0;
}
