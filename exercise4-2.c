#include<stdio.h>
#include<ctype.h>
#define MAXLINE 1000
double atof(char s[])
{
	double val,power;
	int i,sign;
	for(i=0;isspace(s[i]);i++)
		;
	sign= (s[i] == '-')?-1:1;	
	if(s[i] == '+'||s[i]=='-')
		i++;
	for(val = 0.0;isdigit(s[i]);i++)
		val = 10.0*val +(s[i]-'0');
	if(s[i] == '.')
		i++;
	for(power = 1.0;isdigit(s[i]);i++)
	{
		val = 10.0*val+(s[i]-'0');
		power *= 10;
	}
	return sign*val/power;
}
int getlines(char s[] , int lim)
{
	int i,c;
	while(lim-->0&&(c=getchar())!=EOF&&c!='\0')
		s[i++]=c;
	if(c=='\n')
		s[i++] = c;
	s[i]='\0';
	return i;
}
int main()
{
	char s[8]="1234.56";
	double d;
	d= atof(s);
	printf("%f\n",d);
	return 0;
}
