#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid = fork();
    fork();
    fork();
    printf("Child: %d\tParent: %d\t", getpid(), getppid());
    wait(10);
    exit(1);
}