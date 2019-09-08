#include<stdio.h>
int binsearch(int s[],int x,int n)
{
	int low,high,mid;
	low = 0;
	high = n-1;
	mid=(high+low)/2;
	while(low<high&&x!=s[mid])
	{
		if(x>s[mid])
			low=mid+1;
		else
			high=mid-1;
		mid=(high+low)/2;
	}
	if(x==s[mid])
		return mid;
	else
		return -1;
}
int main()
{
	int s[]={2,4,6,7,9,29,45,46,49,50,51};
	printf("%d\n",binsearch(s,45,10));
	return 0;
}
