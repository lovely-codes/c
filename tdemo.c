#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include "ismac.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //初始化互斥锁
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;    //init cond



void *thread1(void*);
void *thread2(void*);
void send_num(int);

int i = 1; //global

int main(void) {
	int mk = 0;
	pthread_t t_a;
	pthread_t t_b; //two thread
	pthread_create(&t_a, NULL, thread2, (void*) NULL);
	sleep(1);
	pthread_create(&t_b, NULL, thread1, (void*) NULL); //Create thread
	pthread_join(t_a,NULL);
	pthread_join(t_b,NULL);
	exit(0);
}

void send_num(int num){
	i = num;
	pthread_mutex_lock(&mutex); //互斥锁
	pthread_cond_signal(&cond); //send sianal to t_b
	pthread_mutex_unlock(&mutex);
#ifdef ISMAC 
	sleep(1);
#endif
}

void *thread1(void *junk) {
	int mk = 0;
	for(;mk<=10;mk++) {
		send_num(mk);
		///pthread_mutex_lock(&mutex); //互斥锁
		///pthread_cond_signal(&cond); //send sianal to t_b
		///pthread_mutex_unlock(&mutex);
	}
}

void *thread2(void *junk) {
	while(i<10) {
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond, &mutex); //wait
		printf("client : %d\n", i);
		pthread_mutex_unlock(&mutex);
	}
}
