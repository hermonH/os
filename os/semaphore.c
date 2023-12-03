#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
void *fun1();
void *fun2();
int shared=1;
sem_t sema;
int main()
{
	pthread_t t1,t2;
	sem_init(&sema,0,1);
	pthread_create(&t1,NULL,fun1,NULL);
	pthread_create(&t2,NULL,fun2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("final value of the shared variable is %d\n",shared);
}

void *fun1()
{
	sem_wait(&sema);
	printf("Thread 1 aquired semaphore\n");
	int x=shared;
	printf("value acquired by thread 1 is %d\n",x);
	x++;
	printf("local increment of the shared variable is %d\n",x);
	shared=x;
	printf("Shared variable value by thread1 is %d\n",shared);
	sem_post(&sema);
	printf("Thread 1 released semaphore");
}

void *fun2()
{
	sem_wait(&sema);
        printf("Thread 2 aquired semaphore\n");
	int y=shared;
	printf("value acquired by thread 2 is %d\n",y);
	y--;
	printf("local decrement of the shared variable is %d\n",y);
	shared=y;
	printf("Shared variable value by thread2 is %d\n",shared);
	sem_post(&sema);
        printf("Thread 2 released semaphore\n");


}
