#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEFLINES 10 /* 默认n=10 */
#define LINES   100 /* 最大打印符号的行 */
#define MAXLEN  100 /* 每一行输入的最大长度 */

void error(char *);
int mgetline(char *,int);

/* 打印输入的最后N行 */

int main(int argc,char *argv[])
{
    char *p;
    char *buf;  
    char *bufend;   

    char line[MAXLEN];
    char *lineptr[LINES];   
    
    int first,i,last,len,n,nlines;

    if( argc == 1)
        n = DEFLINES;

    else if(argc ==2 && (*++argv)[0] == '-')
        n = atoi(argv[0]+1);
    else
        error("Usage: tail [-n]");

    if( n < 1 || n > LINES)
            n = LINES;

    for(i = 0; i < LINES; i++)
            lineptr[i] = NULL;

    if(( p = buf = malloc(LINES * MAXLEN)) == NULL)
        error("tail: cannot allocate buf");
    bufend = buf + LINES + MAXLEN;

    last = 0;
    nlines = 0;

    while((len = getlines(line,MAXLEN)) > 0)
    {
        if(p+len+1 >= bufend)
            p = buf;
        lineptr[last] = p;

        strcpy(lineptr[last],line);
        if(++last >= LINES)
            last = 0;

        p += len + 1;
        nlines++;
    }

    if( n > nlines)
        n = nlines;

    first = last - n;

    if(first < 0)
        first += LINES;
    
    for(i= first; n-- > 0;i = (i+1) % LINES)
        printf("%s",lineptr[i]);

    return 0;
}

/* 打印错误信息并退出 */

void error(char *s)
{
    printf("%s\n",s);
    exit(1);
}

/* 输入 */

int getlines(char s[],int lim)
{
    int c,i;
    
    for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
        s[i] = c;
    if ( c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

