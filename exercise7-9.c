#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINE 1000

int getlines(char *line,int max);

char pattern[]= "ould";

int main()
{
	char line[MAXLINE];
	int found = 0;
	while((getlines(line,MAXLINE))>0)
		if(strindex(line,pattern) >=0){
			printf("%s\n",line);
			found++;
		}
	return 0;
}
int getlines(char *s,int lim)
{
	int c;
	char *t=s;
	while(lim-->0&&(c=getchar())!='X'&&c!='\n')
		*s++=c;
	if(c=='\n')
		*s++=c;
	*s='\0';
	return s-t;
}

int strindex(char *s,char *t)
{
	char *a=s;
	char *p,*r;
	for(;*s!='\0';s++)
	{
		for(p=s,r=t;*r!='\0'&&*p==*r;*p++,*r++)
			;
		if(r>t&&*r=='\0')
			return s-a;
	}
	return -1;
}
