#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[2];
void* playandcount(void *arg){
    unsigned long i=0;
    int a, b;
    pthread_t id=pthread_self();
    if(pthread_equal(id,tid[0])){
        FILE *l;
        char y;
        char v[1024];
        l = fopen ("Novel.txt", "r+");
        while((y = fgetc(l)) != EOF){
                if(strstr(v,"Ifah")) a++; 
        }
        fclose (l);
    }
    else if(pthread_equal(id,tid[1])){
        FILE *l;
        char y;
        char vb[1024];
        l = fopen("Novel.txt", "r+");
        while((y = fgetc(l)) != EOF){
                if(strstr(vb,"Fina")) b++;
        }
        fclose(l);
    }
    printf("Ifah : %d\nFina : %d\n", a,b);
    return NULL;
}

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
