#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void ctrl_c_handler() 
{
   /* printf("SIGINT is ignored so Ctrl+C would not exit the program.....\n");
    signal(SIGINT,SIG_IGN);*/

    signal(SIGINT, SIG_DFL);
    printf("Default Ctrl+C function restored.\n");
   
}

int main() 
{
    signal(SIGINT, ctrl_c_handler);
    
    while (1) 
    {
	printf("Hello World:\n");
	sleep (1);
     
    }
    
}
