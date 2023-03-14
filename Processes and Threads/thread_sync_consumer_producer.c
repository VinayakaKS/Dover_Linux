#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

static pthread_mutex_t mutex =  PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int doneFlag=0;
char buf[100];

void *producer (void *args){
    printf("Producer running\n");
    pthread_mutex_lock(&mutex);
    
    sprintf(buf,"Message\n");
    doneFlag = 1;
    
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);

    printf("Producer exited\n");
}

void *consumer (void *args){
    printf("Consumer running\n");

    pthread_mutex_lock(&mutex);

    if(doneFlag ==0){
        pthread_cond_wait(&cond,&mutex);
    }

    printf("%s",buf);
    
    pthread_mutex_unlock(&mutex);
    printf("Consumer exited\n");
}
void main(){

    pthread_t t1,t2;
    pthread_create(&t1,NULL,producer,NULL);
    pthread_create(&t2,NULL,consumer,NULL);

    printf("Main running\n");
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Main exited\n");
    exit(1);
}