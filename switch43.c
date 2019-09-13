#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXOP 100
#define NUMBER '0'

int sp=0;
int b=0;
double buf[100];
double val[100];

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);

int main()
{
	int type;
	double op;
	char s[MAXOP];
	
	while((type = getop(s))!=EOF)
	{
		switch (type) {
			case NUMBER:
				push(stof(s));
				break;
			case '+':
				push(pop()+pop());
				break;
                        case '*':
                                push(pop()*pop());
                                break;

                        case '-':
				op2=pop();
                                push(pop()-op2);
                                break;

                        case '/':
				op2=pop();
				if(op2!=0.0)
                               		push(pop()/op2);
				else
					printf("error:zero divisor!\n");
				break;
			case '\n':
				printf("\t%.8g\n",pop());
				break;
			default:
				printf("error:unknown command%s\n",s);
	
                                break;

		}
	}
	return 0;
}
void push(double f)
{
	if(sp<100)
	{
		val[sp++]=f;
	}
	else{
		printf("error:stack full");
	}
}
double pop(void)
{
	if(sp>0)
		return val[sp--];
	else{
		printf("error:stack empty\n");
		return 0.0;
	}
}
int getop(char s[])
{
	int i,c;
	while((s[0] = c =getch())==' '||=='\t')
		;
	s[1]= '\0';
	if(!isdigit(c) != '.')
		return c;
	i=0;
	if(isdigit(c))
		while(isdigit(s[i++]=c = getch()))
			;
	if(c =='.')
		while(isdigit(s[i++]=c = getch()))
			;
	s[i]= '\0';
	if(c!=EOF)
		ungetch();
	return NUMBER;
}

int getch()
{
	return (b>0)?buf[b--]:getchar();
}
void ungetch(int c)
{
	if(b > 100)
		printf("ungetch: too many characters\n");
	else
		buf[b++] = c;
}
