#include <unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include <sys/syscall.h>
#define BUFSIZE 1024
int main(int argc, char *argv[])
{
	int f1,f2;
	FILE *fp;
	void filecopy(FILE *, FILE *);
	if (argc == 1) 
		filecopy(stdin, stdout);
	else
	{
		while(--argc > 0)
			if ((f1 = open(argv[1],O_RDONLY,0)) == -1) { 
				printf("cat: can't open %s\n", argv[1]); 
				return 1;
			}
			if ((f2 = open(argv[2],O_RDONLY,0)) == -1) {
                                printf("cat: can't open %s\n", argv[2]);
                                return 1;
                        } 

				filecopy(fp, stdout); 
				close(f1);
				close(f2);
		 	
	}
	return 0;
 }
void filecopy(FILE *ifp,FILE *ofp)
{ 
	int c; 
	while((c=read(0,ifp,BUFSIZE))>0) 
		write(1,ofp,c);
}
