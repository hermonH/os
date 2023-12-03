#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
	int w1,wstatus;
	pid_t q;
	q=fork();
	if(q<0)
		printf("error");
	else if(q==0)
	{
		printf("i am child and my pid is %d\n",getpid());
		printf("My parents pid is %d \n",getppid());
	}
	else
	{
		w1=wait(&wstatus);
		printf("%d\n",w1);
		printf("%d\n",WIFEXITED(wstatus));
		printf("i am parent and my pid is %d\n",getpid());
		printf("mhy child pid is %d \n",q);
	}
	printf("commom\n");
}
