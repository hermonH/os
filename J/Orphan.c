#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
        int pid = fork();
        if(pid == 0)
        {
                printf("Child Process\n");
                printf("ID : %d\nParent ID : %d\n", getpid(),getppid());
                sleep(5);
                printf("Child Process.\n");
                printf("ID : %d\nParent ID : %d\n",getpid(),getppid());
        }
        else if(pid>0)
        {
                printf("Parent process\n");
                printf("ID: %d\n",getpid());
        }
        else
                printf("Failed to create child process.\n");
}
