#include <stdio.h>
float temperature(float f)
{
	float c;
	c = (5.0/9.0) * (f - 32);
	return c; 
}
int main()
{
	float f,c;
	int lower,upper,step;
	
	lower = 0;
	upper = 300;
	step = 20;
	printf("F	C\n");
	f = lower;
	while(f <= upper)
	{
		c = temperature(f);
		printf("%3.0f %6.1f\n",f,c);
		f = f + step;
	}
	return 0;
}
