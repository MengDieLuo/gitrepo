#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 1000

int mystrnlen(char *s)
{
        char *p=s;
        while(*s++ != '\0')
                ;
        return s-p;
}

void mystrncpy(char *s,char *t,int n)
{
	while(*t && n-->0)
		*s++ = *t++;
	int extra=mystrnlen(s) - n;
	while(extra-- >  0)
		*s++;
	*s='\0';
}


int mystrncmp(char *s ,char *t, int n)
{
	while(*s==*t)
	{
		s++;
		t++;
		if(s == '\0' || n-- <= 0)
			return 0;
	}
	return *s-*t;
}

void mystrncat(char *s,char *t,char *str,int n)
{
	while(*s)
	{
		*str++ = *s++;
	}
	while(n-- > 0){
		*str = *t++;
	}
	*str='\0';
}

int main()
{
	
	char dest[]="ABCDEF";
	char source[]="GHIJ";

	mystrncpy(dest,source,4);
	printf("%s\n",dest);

	char s1[]= "ABCD";
	char t1[]= "EFGHIJ";
	char *d;


	if ((d = (char *) malloc(sizeof(char) * (strlen(s1) + + 4 + 1))) == NULL) {
		 printf("unable to allocate memory \n");
			return -1;
        }

	mystrncat(s1,t1,d, 4);
	printf("%s\n", d); /* ABCDEFGH */

	free(d);

	char s2[]= "ABCDEF";
	char t2[]= "ABC";
	int result;

	result = mystrncmp(s2,t2,3);

	printf("%d\n", result);


	return 0;
}
