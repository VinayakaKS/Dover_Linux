#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<mqueue.h>
#include<string.h>

void main(int argc, char *argv[]){

    mqd_t mqd;
    struct mq_attr attrs;
    mq_getattr(mqd,&attrs);

    mqd = mq_open(argv[1],O_CREAT|O_EXCL|O_RDWR,0660,NULL);
    printf("Max_msgs = %ld,Max_msg_size = %ld\n",(int)attrs.mq_maxmsg,(int)attrs.mq_msgsize);

    mq_send(mqd,argv[2],strlen(argv[2]),0);
    printf("%s\n",argv[2]);

    mq_close(mqd); 
}