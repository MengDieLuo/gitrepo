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
void expand(char s[],char t[])
{
	int i,j,k;
	i=j=0;
	while((k=s[i++])!='\0')
	{
		if(s[i]=='-'&&s[i+1]>=k)
		{
			i++;
			while(k<s[i])
				t[j++]=k++;
		}
		else
		{
			t[j++]=k;
		}
	}
	t[j]='\0';
}
int main()
{
	char s[maxlines],t[maxlines];
	getlines(s,maxlines);
	expand(s,t);
	printf("%s",t);
	return 0;
}
