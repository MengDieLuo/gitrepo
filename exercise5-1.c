#include<stdio.h>
#include<ctype.h>

#define SIZE 1000
int getch(void);
void ungetch(int);

int main(void)
{
    int n,array[SIZE];

    for(n=0;n<SIZE && getint(&array[n]) !=EOF; n++)
	;
        printf("%d",array[1]);

    return 0;
}

int getint(int *pn)
{
    int c,sign;

    while(isspace(c=getch()))
    ;
    
    if(!isdigit(c) && c !=EOF && c!='+' && c!='-')
    {
        ungetch(c); 
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;

    if(c=='+' || c=='-')
        c = getch();
    
    for(*pn = 0; isdigit(c);c=getch())
        *pn = 10 * *pn + (c-'0');
    
    *pn *= sign;
        
    if(c!=EOF)
        ungetch(c);

    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int b = 0;

int getch(void)
{
    return (b>0)?buf[b--]:getchar();
}

void ungetch(int c)
{
    if(b >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[b++]=c;
}


