#include<stdio.h>
#define swap(t,x,y) {t z;  z=x; x=y; y=z;}
int main()
{
	char x,y;
	x='a';
	y='b';
	printf("x= %c \t y= %c\n",x,y);
	swap(char,x,y);
	printf("x=%c \t y=%c\n",x,y);
	return 0;
}
