#include <stdio.h>
#define charsum 256
int main()
{
	int c;
	int inspace = 0;
	int freqary[charsum + 1];
	int thisval = 0;
	int maxval = 0;
	int thisid = 0;
	for (thisid = 0; thisid <= charsum; thisid++)
	{
		freqary[thisid] = 0;
	}
	while((c = getchar()) != EOF)
	{
		if(c < charsum)
		{
			thisval = ++freqary[c];
			if(thisval > maxval)
			{
				maxval = thisval;
			}
		}
		else
		{
			thisval = ++freqary[charsum];
                        if(thisval > maxval)
                        {
                                maxval = thisval;
                        }
		}
	}
	for (thisval = maxval; thisval > 0; thisval--)
	{
		printf("%4d  |", thisval);
		for (thisid = 0; thisid <= charsum; thisid++)
		{
			if(freqary[thisid] >= thisval)
			{
				printf("*");
			}
			else if(freqary[thisid] > 0)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("	+");
	for (thisid = 0; thisid < charsum; thisid++)
        {
		if(freqary[thisid] > 0)
		{
			printf("-");
		}
	}
	printf("\n	");
	for (thisid = 0; thisid < charsum; thisid++)
        {
                if(freqary[thisid] > 0)
                {
                        printf("%d",thisid/100);
                }
        }
	printf("\n      ");
	for (thisid = 0; thisid < charsum; thisid++)
        {
                if(freqary[thisid] > 0)
                {
                        printf("%d",(thisid-(100*(thisid/100)))/10);
                }
        }
	printf("\n      ");
	for (thisid = 0; thisid < charsum; thisid++)
        {
                if(freqary[thisid] > 0)
                {
                        printf("%d",(thisid-(10*(thisid/10))));
                }
        }
	if(freqary[charsum] > 0)
	{
	printf(">%d\n",charsum);
	}
	printf("\n");
	return 0;
}
