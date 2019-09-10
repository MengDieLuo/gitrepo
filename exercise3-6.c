#include<stdio.h>
#include<limits.h>
#include<string.h>
int reverse(char s[])
{
        int c,i,j;
        for ( i = 0, j = strlen(s)-1; i < j; i++, j--)
        {
                c=s[i];
                s[i]=s[j];
                s[j]=c;
        }
}
void itoa(int n,char s[],int w)
{
        int i=0,sign=n;
	if(sign<0)
		n=-n;
        do{
                s[i++]=n%10+'0';
		printf("%d %% %d + '0'=%d\n",n,10,s[i-1]);
        }while((n /= 10)>0);
        if(sign < 0)
        {
                s[i++] = '-';
        }
	while(i<w)
		s[i++]=' ';
        s[i] = '\0';
        reverse(s);
}
int main()
{
	char s[100];
	itoa(INT_MIN,s,7);
	printf("%s",s);
	return 0;
}
