#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
int i=2;
void oh(int sig)
{
	printf("Pressed Ctrl+C\n");
    i--;
    signal(SIGINT,oh);
    if(i==0)
    {
        printf("Restoring to default.\n");
        signal(SIGINT,SIG_DFL);
    }
}
int main(){
	signal(SIGINT,oh);
	while(1)
    {
		printf("Hello World!\n");
		sleep(1);
	}
}