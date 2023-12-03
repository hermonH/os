#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
    pid_t pid;
    pid = fork();
    if(pid > 0)
    {
        int i = 0;
        while(i++ < 6)
        {
            printf("Parent process.\n");
            sleep(1);
        }
    }
    else if (pid == 0)
    {
        int i = 0;
        while(i++ < 6)
        {
            printf("Child process.\n");
            sleep(1);
            if(i==2)
            {
                kill(getppid(),SIGSTOP);
                printf("Parent stoppped\n");
            }
            if(i==5)
            {
                kill(getppid(),SIGCONT);
                printf("Parent Process Resumed.\n");
            }
        }
    }
}