#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

static int glob;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static void* thread1(void *args){
    int loc;
    pthread_mutex_lock(&mutex);
    printf("T1 is running\n");
    for (int i =0;i<10000;i++){
        loc = glob;
        loc++;
        glob=loc++;
    }  
    pthread_mutex_unlock(&mutex); 
}

static void* thread2(void *args){
    int loc;
    pthread_mutex_lock(&mutex); 
    printf("T2 is running\n");
       for (int i =0;i<10000;i++){
        loc = glob;
        loc++;
        glob=loc++;
    }
    pthread_mutex_unlock(&mutex); 

}

void main(){
    pthread_t t1,t2;
    void *res1;
    void *res2;

    if(pthread_create(&t1,NULL,thread1,"T1") != 0)
        perror("Error : ");

    if(pthread_create(&t2,NULL,thread2,"T2") != 0)
        perror("Error : ");

    pthread_join(t1,&res1);
    pthread_join(t2,&res2);

    printf("gloal var - %d\n",glob);
    printf("Main thread exiting\n");
    pthread_exit(NULL);

}