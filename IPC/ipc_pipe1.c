#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

void main(){

    int fd[2];
    int s;
    char buf[50];
    char data[50]; 
    s=pipe(fd);

    //Writing message
    sprintf(data,"Hello man!");
    write(fd[1],data,10);

    //Reading message
    read(fd[0],buf,2);
    printf("%s\n",buf);

    read(fd[0],buf,8);
    printf("%s\n",buf);

    printf("Read and write complete\n");
    sleep(15);
}