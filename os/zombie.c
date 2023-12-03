#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
int main()
{
        pid_t q;
        q=fork();
        if(q<0)
                printf("error");
        else if(q==0)
        {
		sleep(2);
                printf("i am child and my pid is %d\n",getpid());
                printf("My parents pid is %d \n",getppid());
        }
        else
        {
			sleep(5);
                        printf("i am parent parent is %d \n",getpid());
			printf("my child pid is %d\n",q);
        }
} 
