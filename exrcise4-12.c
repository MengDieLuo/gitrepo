#include<stdio.h>
#include<math.h>

#define MAXLEN 100

void itoa(int n,char s[]);


int main(void)
{
    int n;
    char s[MAXLEN];

    n = 1723;

    itoa(n,s);

    printf("%s\n",s);

    return 0;
}

void itoa(int n,char s[])
{
    static int i;

    if(n/10)
        itoa(n/10,s);
    else
    {
        i = 0;
        if( n < 0)
            s[i++]='-';
    }

    s[i++] = abs(n) % 10 + '0';

    s[i] = '\0';

}
 
