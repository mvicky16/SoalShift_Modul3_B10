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

int main(void){
    int i=0;
    int x;
    while(i<2){
	pthread_create(&(tid[i]),NULL,&playandcount,NULL);
        i++;
    }
    while(){
    	printf("status Kepiting : %d\nstatus Lohan : %d\n",statk, statl);   
    	printf("1.Memberi makan Kepiting\n");
    	printf("2.Memberi makan Lohan\n");
    	printf("1 / 2 ?\n");
    	scanf("%d",&x);

    	if (x == 1) statk = statk + 10;
    	else if (x == 2) statl = statl + 10;
    }
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    return 0;
}
