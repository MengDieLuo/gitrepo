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
	char line[maxlines];
	int t,len;
	int comment,quote;
	t = comment = quote = 0;
	while((len = getlines(line,maxlines))>0)
	{
		t=0;
		while(t< len)
		{
			if(line[t] == '"')
				quote = 1;
			if(!quote)
			{
				if(line[t] == '/'&&line[t+1] == '*')
				{
					t=t+2;
					comment = 1;
				}
				if(line[t] == '*'&&line[t+1] == '/')
                                {
                                        t=t+2;
                                        comment = 0;
                                }
				if(comment == 1)
				{
					t++;
				}
				else
				{
					printf("%c",line[t]);
					t++;
				}
			}
			else
			{
				printf("%c",line[t]);
                                t++;
			}
		}
	}
	return 0;
}
