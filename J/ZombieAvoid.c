#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{	
	int pid=fork();
	if(pid==0)
	{
		for(int i=0;i<2;i++)
			printf("I am child.\n");
	}
	else
	{
		wait(NULL);
		printf("I am parent.\n");
		while(1);
	}
}
