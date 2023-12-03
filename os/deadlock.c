#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *fun1();
void *fun2();
int shared=1;
pthread_mutex_t lock1,lock2;
int main()
{
        pthread_t t1,t2;
        pthread_mutex_init(&lock1,NULL);
	pthread_mutex_init(&lock2,NULL);
        pthread_create(&t1,NULL,fun1,NULL);
        pthread_create(&t2,NULL,fun2,NULL);
        pthread_join(t1,NULL);
        pthread_join(t2,NULL);
        printf("final value of the shared variable is %d\n",shared);
}

void *fun1()
{
	printf("Thread 1 trying to aqcuire lock 1\n");
        pthread_mutex_lock(&lock1);
        printf("Thread 1 aquired lock 1\n");
        sleep(1);
        printf("Thread 1 trying to aqcuire lock 2\n");
        pthread_mutex_lock(&lock2);
	printf("Thread 1 aquired lock 2\n");

        pthread_mutex_unlock(&lock1);
	pthread_mutex_unlock(&lock2);
        printf("Thread 1 released lock 1 and lock 2");
}

void *fun2()
{
	printf("thread 2 trying to acquire lock 2\n");
        pthread_mutex_lock(&lock2);
        printf("Thread 2 aquired lock 2\n");
        sleep(1);
        printf("Thread 2 trying to acquire lock 1\n");
        pthread_mutex_lock(&lock1);
        printf("Thread 2 acquired lock 1\n");
	pthread_mutex_unlock(&lock1);
        pthread_mutex_unlock(&lock2);
        printf("Thread 2 released lock 1 and lock 2");


}
