#include<stdio.h>
#include<unistd.h>

int main()
{
	char *const evp[] = {"PATH=/bin:/usr/bin","TERM:console",0};
	printf("Before execl\n");
	execl("/bin/ps","ps","-a",NULL);
	printf("After execlp\n");
}