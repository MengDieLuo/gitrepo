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
int any(char s1[],char s2[])
{
	int i,j,k=0;
	for (i=0;s1[i]!='\0';i++)
	{
		for(j=0;s2[j]!='\0';j++)
		{
			if(s1[i]==s2[j])
			{
				return i;
			}
		}
	}
	return -1;
}
int main()
{
	char s1[maxlines],s2[maxlines];
	getlines(s1,maxlines);
	getlines(s2,maxlines);
	int a=any(s1,s2);
	if(a==-1)
	{
		printf("cannot find\n");
	}else
	{
		printf("%d\n",a);
	}
	return 0;
}
