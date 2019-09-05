#include<stdio.h>
#define maxs 100
int main()
{
        int i=0;
        int lim=maxs;
        int c;
        char s[maxs];
        while(i < (lim-1))
        {
                c = getchar();
                if(c == EOF)
                        break;
                else if (c == '\n')
                        break;
                s[i++] = c;
        }
        s[i]='\0';

        return 0;
}
