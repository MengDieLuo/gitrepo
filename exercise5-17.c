#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define NUMERIC  1 
#define FOLD     4
#define NUMERIC   1 
#define DECR      2 
#define LINES     100
#define MAXSTR 100
#define MDIR 8


int charcmp(char *,char *);
int numcmp(char *,char *);
void error(char *);
void readargs(int argc,char *argv[]);
int readlines(char *lineptr[],int maxlines);
void myqsort(void *v[],int left,int right,int (*comp)(void *,void *));
void writelines(char *lineptr[],int nlines,int decr);

int  option = 0;
int pos1=0;
int pos2=0;


int main(int argc,char *argv[])
{
    char *lineptr[LINES];
    int nlines;     
    int rc=0;
	readargs(argc,argv);
	if((nlines = readlines(lineptr,LINES))>0)
    {
        if(option & NUMERIC)
            myqsort((void **)lineptr,0,nlines-1,(int (*)(void *,void *))numcmp);
        else
            myqsort((void **)lineptr,0,nlines-1,(int (*)(void *,void *))charcmp);

        writelines(lineptr,nlines,option & DECR);
    }
    else
    {
        printf("input too big to sort \n");
        rc = -1;
    }

    return rc;

}

void readargs(int argc,char *argv[])
{
	int c;
    int atoi(char *);
    
    while(--argc > 0 && (c=(*++argv)[0])=='-' || c == '+')
    {
        if( c == '-' && !isdigit(*(argv[0]+1)))
            while( c = *++argv[0])
                switch(c)
                {
                case 'd':   /* directory order */
                    option |= MDIR;
                    break;
                case 'f':
                        /* fold upper and lower */
                    option |= FOLD;
                    break;
                case 'n':
                        /* numeric sort */
                    option |= NUMERIC;
                    break;
                case 'r':
                    option |= DECR;
                    break;
                default:
                    printf("sort: illegal option %c \n",c);
                    error("Usage: sort -dfnr [+pos1] [-pos2]");
                    break;
                }
        else if( c == '-')
            pos2 = atoi(argv[0]+1);
        else if((pos1 = atoi(argv[0]+1))<0)
            error("Usage: sort -dfnr [+pos1][-pos2]");
    }

    if(argc || pos1 > pos2)
        error("Usage: sort -dfnr [+pos1] [-pos2]");
}

void substr(char *s,char *t,int maxstr);

/* 写输出行 */

/* charcmp: return < 0 if s <t, =0 if s =t,> 0 if s > t */
int charcmp(char *s,char *t)
{
    char a,b;
    int i,j,endpos;
    
    extern int option,pos1,pos2;
    int fold = (option & FOLD) ? 1 : 0;
    int dir = (option & MDIR) ? 1 : 0;

    i=j=pos1;

    if (pos2 > 0)
        endpos = pos2;
    else if ((endpos = strlen(s)) > strlen(t))
        endpos = strlen(t);

    do
    {
        if(dir)
        {
            while(i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] !='\0')
                s[i] != ' ' && s[i] != '\0';
                    i++;
            while(j < endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0')
                t[j] != ' ' && t[j] != '\0';
                    j++;
        }
        if(i < endpos && j < endpos)
        {
            a = fold ? tolower(s[i]):s[i];
            i++;
            b = fold ? tolower(t[j]):t[j];
            j++;
        
            if(a==b && a == '\0')
                return 0;
        }
    }while(a == b && i < endpos && j < endpos);

    return a - b;

}

void substr(char *s,char *str,int max)
{
    int i,j,len;
    extern int pos1,pos2;

    len = strlen(s);
        
    if( pos2 > 0 && len > pos2)
        len = pos2;
    else if ( pos2 > 0 && len < pos2)
        error("substr: string too short");
    for( j =0, i = pos1; i< len;i++,j++)
        str[j] = str[i];
    str[j] = '\0';
}

void error(char *s)
{
    printf("%s \n",s);
    exit(1);
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

void myqsort(void *v[],int left,int right,int (*comp)(void *,void *))
{
    int i,last;
    void swap(void *v[],int,int);

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

void swap(void *v[],int i,int j)
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

