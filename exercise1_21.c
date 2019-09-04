#include<stdio.h>
#define TAB 8
int main()
{
        int nb,nt,pos,c;
        nb = nt = 0;
        pos = 1;
        while((c=getchar())!=EOF)
        {
                if (c == ' ')
                {
                	if(pos%TAB != 0)
			{
				nb++;
			}
			else
			{
				nb=0;
				nt++;
			}
		}
                else 
                {
                       if(nt > 0)
			{
				putchar('\t');
				nt--;
			}
			if(c == '\t')
				nb = 0;
			else
				if(nb>0)
				{
					putchar(' ');
					nb--;
				}
			putchar(c);
			if(c == '\n')
			{
				pos=0;
			}
			else if(c == '\t')
			{
				pos = pos+(TAB-(pos-1)%TAB)-1;
			}
                }
		pos++;
          
        }
        return 0;
}
