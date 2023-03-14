#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<mqueue.h>
void main(int argc,char *argv[]){

    mqd_t mqd;
    char buf[5];
    struct mq_attr attrs;

    mqd = mq_open(argv[1],O_RDWR);
    mq_getattr(mqd,&attrs);

    //buf = calloc(1,attrs.mq_msgsize);
    mq_receive(mqd,buf,2,0);
    printf("%s\n",buf);

    mq_close(mqd);
}