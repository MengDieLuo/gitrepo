#include<stdio.h>
#define maxlines 1000
char line[maxlines];
int getlines(char s[],int lim)
{
        int c,i,j;
        for (i = 0;i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i )
        {
                s[i]=c;
        }
        if(c == '\n')
        {

                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
} 
int main()
{
	int len,t,a,b,c,sq,dq;
	len=t=a=b=c=0;
	sq=1;
	dq=1;
	while((len = getlines(line,maxlines))>0)
	{
		t=0;
		while(t<len)
		{
			if(line[t]=='[')
				a++;
			if(line[t]==']')
				a--;
			if(line[t]=='(')
				b++;
                        if(line[t]==')')
				b--;
			if(line[t]=='{')
				c++;
                        if(line[t]=='}')
				c--;
			if(line[t]=='\'')
				sq*=-1;
                        if(line[t]=='"')
				dq*=-1;
			t++;
		}
	}
	if(dq!=1)
		printf ("Mismatching double quote mark\n");
	if(sq!=1)
		printf ("Mismatching single quote mark\n");
	if(a!=0)
		printf ("Mismatching brace mark\n");
	if(b!=0)
		printf ("Mismatching parenthesis\n");
	if(c!=0)
		printf ("Mismatching bracket mark\n");
	if(a==0&&b==0&&c==0&&sq==1&&dq==1)
		printf ("Syntax appears to be correct.\n");
	return 0;
}
