#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid = fork();
    if(pid<0)
    {
        printf("Unsuccessful fork\n");
        exit(1);
    }
    else if(pid==0)
        printf("Child\n");
    else 
        printf("Parent\n");
}