#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    fork();
    fork();
    fork();
    printf("%d %d\n", getpid(),getppid());
    exit(0);
}