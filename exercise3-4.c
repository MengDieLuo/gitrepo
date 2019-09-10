#include <stdio.h>
#include <string.h>
#include <limits.h>
void reverse(char s[])
{
	int c,i,j;
	for ( i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		c=s[i];
		s[i]=s[j];
		s[j]=c;
	}
}
void itoa(int n,char s[])
{
	int i=0,sign=n;
	do{
		s[i++]=abs(n%10)+'0';
	}while(n /= 10);
	if(sign < 0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}
int main()
{
	char s[20];
	printf("INT_MAIN:%d\n",INT_MIN);
	itoa(INT_MIN,s);
	printf("s:%s\n",s);
	return 0;
}
