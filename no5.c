#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[2];

int main(void){
    int i=0;
    while(i<2){
        pthread_create(&(tid[i]),NULL,&playandcount,NULL);
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
