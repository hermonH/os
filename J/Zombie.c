#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
        int pid=fork();
        if(pid == 0)
        {
                for(int i=0;i<2;i++)
                        printf("Child Process\n");
        }
        else if(pid>0)
        {
                printf("Parent Process\n");
                while(1);
        }
}
