#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define FOLD      4
#define NUMERIC   1 
#define DECR      2 
#define LINES     100

int charcmp(char *,char *);
int numcmp(char *,char *);
int readlines(char *lineptr[],int maxlines);
void myqsort(char *v[],int left,int right,int (*comp)(void *,void *));
void writelines(char *lineptr[],int nlines,int decr);

static char option = 0;

int main(int argc,char *argv[])
{
    char *lineptr[LINES];
    int nlines;     
    int c,rc=0;    
   while(--argc > 0 && (*++argv)[0] == '-') {
        while(c = *++argv[0])
            switch(c)
            {
                case 'f':
                        option |= FOLD;
                        break;
                case 'n':
                        option |= NUMERIC;
                        break;
                case 'r':
                        option |= DECR;
                        break;
                default:
                        printf("sort: illegal option %c\n",c);
                        argc=1;
                        rc=-1;
                        break;
            }
    }
    if (argc)
        printf("Usage: sort -fnr \n");
    else
    {
        if((nlines=readlines(lineptr,LINES)) > 0)
        {
            if(option & NUMERIC)
                myqsort((char **)lineptr,0,nlines-1,(int (*)(void *,void *))numcmp);
            else if (option & FOLD)
                myqsort((char **)lineptr,0,nlines-1,(int (*)(void *,void *))charcmp);
            else
                myqsort((char **)lineptr,0,nlines-1,(int (*)(void *,void *))strcmp);

            writelines(lineptr,nlines,option & DECR);
        }
        else
        {
            printf("input too big to sort \n");
            rc = -1;
        }

    return rc;
	}
}

/* charcmp: return < 0 if s <t, =0 if s =t,> 0 if s > t */
int charcmp(char *s,char *t)
{
    for(;tolower(*s) == tolower(*t);s++,t++)
        if(*s == '\0')
            return 0;
    return tolower(*s) - tolower(*t);
}


#include<stdlib.h>
/* numcmp: 数字序比较s1和s2 */
int numcmp(char *s1,char *s2)
{
    double v1,v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if( v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

#define MAXLEN 1000 
int getlines(char *,int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[],int maxlines)
{
    int len,nlines;
    char *p,line[MAXLEN];
    nlines = 0;
    while((len = getlines(line,MAXLEN)) > 0)
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len-1] = '\0'; 
           strcpy(p,line);
            lineptr[nlines++]=p;
        }
    return nlines;
}


#define ALLOCSIZE 1000  /* 可变存储的最大长度 */
static char allocbuf[ALLOCSIZE];    /* 动态存储 */
static char *allocp=allocbuf;       /* 下一个空节点 */

char *alloc(int n)  /* */
{
    if(allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp -n;
    }
    else
        return 0;
}

void afree(char *p) /* 释放链表 */
{
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

/* 不仅可以交换数组，还可以交换函数 */

void myqsort(char *v[],int left,int right,int (*comp)(void *,void *))
{
    int i,last;
    void swap(char *v[],int,int);

    if(left >= right)
        return;

    swap(v,left,(left+right)/2);

    last = left;

    for(i=left+1;i<=right;i++)
        if((*comp)(v[i],v[left])<0)
            swap(v,++last,i);
    swap(v,left,last);

    myqsort(v,left,last-1,comp);
    myqsort(v,last+1,right,comp);
}

void swap(char *v[],int i,int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


void writelines(char *lineptr[],int nlines, int decr)
{
    int i;
    for(i=0;i<nlines;i++)
        printf("%s\n",lineptr[i]);
}



int getlines(char s[],int lim)
{
    int c,i;

    for(i=0;i<lim-1 && (c=getchar())!= EOF && c!='\n';i++)
        s[i] = c;
    if( c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

