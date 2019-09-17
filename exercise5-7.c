#include<stdio.h>
#include<string.h>
#define MAXLINES 1000
char *s[MAXLINES];
char t[MAXLINES];

int readlines(char *s[],char *t,int n);
void writelines(char *s[],int n);

void qsort(char *s[],int l,int r);

int main()
{
	int n;
	if((n=readlines(s,t,MAXLINES))>=0)
	{
		qsort(s,0,n-1);
		writelines(s,n);
		return 0;
	}else
	{
		printf("error: input too big to sort \n");
		return 1;
	}

}
#define MAXLEN 1000
#define MAXSTOR 5000

int getlines(char *s,int lim);
char *alloc(int);
int readlines(char *s[],char *t,int maxlines)
{
          int len,n;
          char line[MAXLEN];
          char *p = t;
          char *linestop = t + MAXSTOR;

          n=0;

          while((len=getlines(line,MAXLEN)) > 0)
                    if(n >= maxlines || p+len > linestop)
                              return -1;
                    else
                    {
                              line[len-1] = '\0';
                              strcpy(p,line);
                              s[n++]=p;
                              p+=len;
                    }
	return n;
}
void writelines(char *s[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%s\n",s[i]);
}

void qsort(char *v[],int left,int right)
{
      int i,last;
      void swap(char *v[],int i,int j);

      if(left >= right)
            return;
      swap(v,left,(left+right)/2);

      last = left;

      for(i=left+1;i<=right;i++)
            if(strcmp(v[i],v[left])<0)
                  swap(v,++last,i);
      swap(v,left,last);
      qsort(v,left,last-1);
      qsort(v,last+1,right);
}

void swap(char *v[],int i,int j)
{
	char *temp;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
	if(allocbuf +ALLOCSIZE -allocp >=n)
	{
		allocp +=n;
		return allocp - n;
	}
	else
		return 0;

}

int getlines(char *s,int lim)
{
	int c;
	char *t=s;
	while(lim-->=0&&(c=getchar())!=EOF&&c!='\n')
		*s++ = c;
	if(c == '\n')
		*s++ = c;
	*s='\0';
	return s-t;
}
