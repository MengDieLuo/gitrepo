
#include<stdio.h>
#include<ctype.h>

#define SIZE 1000
int getch(void);
void ungetch(int);
int getfloat(float *);

int main(void)
{
    int n,s;
    float array[SIZE];

    for(n=0;n<SIZE && getfloat(&array[n]) !=EOF; n++)
	;
    
    for(s=n;s>=0; s--)
        printf("%d",array[s]);

    return 0;
}

int getfloat(float *pn)
{
    int c,sign;
    float power;
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
    
    for(*pn = 0.0; isdigit(c);c=getch())
        *pn = 10.0 * *pn + (c-'0');
	if(c=='.')
		c=getch();
    for(power=1.0;isdigit(c);c=getch())
    {
	 *pn = 10.0 * *pn + (c - '0');  
    	 power *= 10.0;
    }
    *pn *= sign/power;
        
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


