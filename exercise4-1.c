#include<stdio.h>
#define MAXLINE 1000
char t[]="abc";
int getlines(char s[],int lim)
{
	int c,i;
	i=0;
	while(lim-->0&&(c=getchar())!=EOF && c!='\n')
	{
		s[i++]=c;
	}
	if(c == '\n')
		s[i++]=c;
	s[i]='\0';
	return i;
}	
int strindex(char s[], char t[])
{
	int i,j,k;
	for(i=0;s[i]!='\0';i++)
	{
		for(j=i,k=0;t[k]!='\0'&&s[j]==t[k];j++,k++)
			;
		if(k>0&&t[k]=='\0')
			return i;
	}
	return -i;
}
int main()
{
	char line[MAXLINE];
	int f=0;
	while(getlines(line,MAXLINE)>0)
		if(strindex(line,t)>=0)
		{
			printf("%s\n",line);
			printf("%d",strindex(line,t));
			f++;
		}
	printf("no found");
	
	return f;
}
