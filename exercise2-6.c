#include<stdio.h>
unsigned setbits(unsigned x,int p,int n,unsigned y)
{
	return (x & ((~0 << (p + 1)) | (~(~0 << (p + 1 - n))))) | ((y & ~(~0 << n)) << (p + 1 - n));
}
int main()
{
	printf("%u",setbits((unsigned)12,3,2,(unsigned)57));
	return 0;
}
