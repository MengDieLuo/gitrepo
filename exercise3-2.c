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
void escape(char s[],char t[])
{

	int i,j;
	i=j=0;
	while(t[i]!='\0')
	{
		switch(t[i])
		{
			case '\t':
				s[j]='\\';
				j++;
				s[j]='t';
				break;
			case '\n':
                                s[j]='\\';
                                j++;
                                s[j]='n';
                                break;
			default:
				s[j]=t[i];
				break;
		}
		i++;
		j++;
	}
	s[j]='\0';
}
int main()
{
	char s[maxlines],t[maxlines];
	getlines(t,maxlines);
	escape(s,t);
	printf("%s",s);

	return 0;
}
