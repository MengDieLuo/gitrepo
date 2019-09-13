#include<stdio.h>
#include<stdlib.h>

#define MAXbuf 100
#define MAXLINE 100

int b=0;
int buf[MAXLINE];


int getch(void);
void ungetch(int c);

int main(void)
{
	int c;
	c = '*';
	ungetch(c);

	while((c=getch())!=EOF)
		putchar(c);
	return 0;
}
void ungetch(int c)
{
	if(b!=0)
		 printf("ungetch: too many characters\n");
	else
		b=c;
}
int getch(void)
{
	return (b>0)?buf[b--]:getchar();
}

