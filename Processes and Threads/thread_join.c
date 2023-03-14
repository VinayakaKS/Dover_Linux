#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

static void* thread1(void *args){
    char * arg = (char *)args;
    printf("thread 1 is running\n");
    sleep(4);
    printf("thread1 exited\n");
    return "ret from thread1";
}

static void* thread2(void *args){
    char * arg = (char *)args;
    printf("thread 2 is running\n");
    sleep(4);
    int k =10;
    pthread_detach(pthread_self());

    printf("thread2 exited\n");
    printf("K is %d\n",k);
    return "ret from thread2";
}

void main(){
    pthread_t t1,t2;
    void *res1;
    void *res2;

    if(pthread_create(&t1,NULL,thread1,"T1") != 0)
        perror("Error : ");

    if(pthread_create(&t2,NULL,thread2,"T2") != 0)
        perror("Error : ");
   
    printf("Main thread running\n");
    
    // pthread_join(t1,&res1);
    // pthread_join(t2,&res2);

    // printf("%s\n",(char *)res1);
    // printf("%s\n",(char *)res2);

    printf("Main thread exiting\n");
    pthread_exit(NULL);

}