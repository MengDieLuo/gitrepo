#include<stdio.h>
#include<stdlib.h>

#define MAXbuf 100
#define MAXLINE 100

int b=0;
int buf[MAxbuf];

int getch(void);
void ungetch(int c);
void ungets(char s[]);
int getlines(char s[],int lim);

int main(void)
{
	char line[MAXLINE];
	int c;
	getlines(line,MAXLINE);
	ungets(line);

	while((c=getch())!=EOF)
		putchar(c);
	return 0;
}
int getlines(char s[],int lim)
{
	int i,c;
	while(lim-->0&&c=getchar()!=EOF&&c!='\n')
		s[i++]=c;
	if(c=='\n')
		s[i++] = c;
	s[i]='\0';
	return i;
		
}
void ungets(char s[])
{
	int i;
	i=strlen(s);
	while(i>0)
		ungetch(s[i--]);
}
void ungetch(int c)
{
	if(b>=MAXbuf)
		 printf("ungetch: too many characters\n");
	else
		buf[b++]=c;
}
int getch(void)
{
	return (b> 0)?buf[b--]:getchar();
}
