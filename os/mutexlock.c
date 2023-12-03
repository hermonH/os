#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *fun1();
void *fun2();
int shared=1;
pthread_mutex_t lock;
int main()
{
        pthread_t t1,t2;
        pthread_mutex_init(&lock,NULL);
        pthread_create(&t1,NULL,fun1,NULL);
        pthread_create(&t2,NULL,fun2,NULL);
        pthread_join(t1,NULL);
        pthread_join(t2,NULL);
        printf("final value of the shared variable is %d\n",shared);
}

void *fun1()
{
        pthread_mutex_lock(&lock);
        printf("Thread 1 aquired lock\n");
        int x=shared;
        printf("value acquired by thread 1 is %d\n",x);
        x++;
        printf("local increment of the shared variable is %d\n",x);
        shared=x;
        printf("Shared variable value by thread1 is %d\n",shared);
        pthread_mutex_unlock(&lock);
        printf("Thread 1 released lock");
}

void *fun2()
{
        pthread_mutex_lock(&lock);
        printf("Thread 2 aquired lock\n");
        int y=shared;
        printf("value acquired by thread 2 is %d\n",y);
        y--;
        printf("local decrement of the shared variable is %d\n",y);
	shared=y;
	printf("shared varibale value by thread 2 %d\n",shared);
	pthread_mutex_unlock(&lock);
        printf("Thread 2 released lock\n");


}


