#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	pid_t p;
	int fd[2];
	int newfd[2];
	pipe(fd);
	pipe(newfd);
	p=fork();
	if(p==0){
		sleep(2);
		char buffer[50];
		printf("child reading from parent\n");
		int n=read(fd[0],buffer,30);
		close(fd[0]);
		write(1,buffer,n);
		sleep(1);
		printf("CHILD WRITING TO PARENT\n");
		write(newfd[1],"hello from my side too my parent\n",34);
		close(newfd[1]);

	}
	else{
		printf("PARENT IS WRITING TO CHILD\n");
		write(fd[1],"hello child i am your parent\n",30);
		close(fd[1]);
		wait(NULL);
		char buffer[50];
		int n=read(newfd[0],buffer,34);
		close(newfd[0]);
		printf("parent reading from child\n");
		write(1,buffer,n);

	}
}
