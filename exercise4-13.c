#include<stdio.h>
#include<string.h>

#define maxlines 100

int getlines(char line[],int lim);
void reverse(char s[]);

int main(void)
{
    char s[maxlines];

    int ss=getlines(s,maxlines);
    if(ss>0)
    {
	reverse(s);
	printf("%s\n",s);
    }
    return 0;
}

int getlines(char s[],int lim)
{
    int i,c;
    for(i=0;i<(lim-1)&&(c=getchar())!=EOF&&c!='\n';i++)
		s[i]=c;
    if(c=='\n')
        s[i++]=c;

    s[i]='\0';
	return i;
}

void reverse(char s[])
{
    void reverser(char s[],int i,int len);

    reverser(s,0,strlen(s));
}

void reverser(char s[],int i,int len)
{
    int c,j;

    j = len - (i + 1);
    
    if( i < j )
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;

        reverser(s,i++,len);
    }
}

