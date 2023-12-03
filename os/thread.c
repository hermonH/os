#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *thread_func(void *args);
int i,j;
int num[] ={1,2};
int main()
{
        pthread_t t;
        pthread_create(&t,NULL,thread_func,(void *)num);
        void *sum;
	pthread_join(t,&sum);
        printf("After thread  finished\n");
	printf("%s",(char *)sum);
}


void *thread_func(void *args)
{
	int *x=args;
        int sum = x[0]+x[1];
	pthread_exit("passer");
}
