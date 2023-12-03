#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int n=5;
    printf("Original Variable: %d\n", n);
    int pid = fork();
    if(pid == 0)
    {
        printf("Child Variable Before: %d\n", n);
        n = 10;
        printf("Child Variable After: %d\n", n);
    }
    else if(pid > 0)
    {
        printf("Parent Variable Before: %d\n", n);
        n = 20;
        printf("Parent Variable After: %d\n", n);
    }
    else 
    {
        printf("Unsuccessful to Create");
        exit(0);
    }
}