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
void mystract(char *s,char *t)
{
	while(*s!='\0')
	{
		s++;
	}
	s--;
	while((*s++ = *t++)!='\0')
		;	
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

	mystract(s,t);
	printf("%s",s);

	return 0;
}
