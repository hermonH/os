#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int fdp[2],n;
	pipe(fdp);
	pid_t q = fork();
	if(q==0)
	{
		char buffer[50];
		int n=read(fdp[0],buffer,50);
		write(1,buffer,n);
		printf("\n");
	}
	else
	{
		char buffer[50];
		sprintf(buffer,"My name is Asad");
		write(fdp[1],buffer,10);
	}
}



