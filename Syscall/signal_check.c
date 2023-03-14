#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void signal_handler(int signo){
    if(signo == SIGINT)
        printf("Caught SIGINT\n");
    if(signo == SIGTERM)
        printf("Caught SIGTERM\n");
}
void main(){
    printf("%d\n",getpid());

    if(signal(SIGINT,/*signal_handler*/SIG_IGN)==SIG_ERR){
    fprintf(stderr,"Cannot handle SIGINT\n");
    exit(-1);
    }

    if(signal(SIGTERM,signal_handler)==SIG_ERR){
    fprintf(stderr,"Cannot handle SIGTERM\n");
    exit(-1);
    }
    while(1);
}
