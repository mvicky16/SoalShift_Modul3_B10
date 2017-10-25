#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[2];
int statl = 100, statk = 100, stats = 0;
void* playandcount(void *arg){
    unsigned long i=0;
    pthread_t id=pthread_self();
    int iter;
    if(pthread_equal(id,tid[0])){
        while(statk > 0 && statk <=100){
		sleep(20);
		statk = statk - 10;
	}
	printf("game over\n");
    }
    else if(pthread_equal(id,tid[1])){
	while(statl > 0 && statl <= 100){
		sleep(10);
		statl = statl - 15;
	}
	printf("game over\n");
    }
    return NULL;
}
