#include<stdio.h>
#define MAXLINE 1000

int getlines(char s[],int lim)
{
        int c,i;
        for(i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';i++)
                s[i]=c;
        if(c=='\n')
                s[i++]=c;
        s[i]='\0';
        return i;
}

int strend(char *s, char *t)
{
	int len=mystrlen(t);
	while(*s!='\0')
		s++;
	s--;
	while(*t!='\0')
		t++;
	t--;
	while(len>0)
	{
		if(*t-- == *s--)
			len--;
		else
			return 0;
	}
	if(len == 0)
		return 1;
}

int mystrlen(char *t)
{
	char *p;
	p=t;
	while(*p++ != '\0')
		;
	return p-t;
}

int main()
{
        int len;
        char s[MAXLINE],t[MAXLINE];

        putchar('s');
        putchar(':');
        getlines(s,MAXLINE);

        putchar('t');
        putchar(':');
        getlines(t,MAXLINE);

	len=strend(s,t);
	printf("%d",len);

	return 0;
}
