#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
    pid_t ppid,pid,cpid;
    pid = fork();
    if(pid > 0)
    {
        int i = 0;
        while(i++ < 5)
        {
            printf("Parent process.\n");
            sleep(1);
        }
    }
    else if (pid == 0)
    {
        int i = 0;
        while(i++ < 5)
        {
            printf("Child process.\n");
            sleep(1);
            if(i==3)
            {
                kill(getppid(),SIGKILL);
                printf("Parent killed. Orphan Process\n");
            }
        }
    }
    else
    {
        printf("Something bad happened.");
        exit(EXIT_FAILURE);
    }
}