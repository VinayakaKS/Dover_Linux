#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

static void * thread2(void *args){
    char *str = (char *)args;
    printf("Thread with pid - %d taking args from main thread - %s \n",getpid(),str);
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
    sleep(20);
   
    printf("Thread 2 exited\n");
    pthread_exit(0);
}
void main(){

    int s;
    pthread_t t;
    // void *res;

    s = pthread_create(&t,NULL,thread2,"Hai passed\n");
    if(s!=0)
        perror("Error creating thread");

    printf("Passing args to thread2 as pid = %d\n",getpid());
    sleep(5);
    printf("Main thread exiting\n");
    // pthread_detach(t);
    pthread_cancel(t);
    pthread_exit(0);
}