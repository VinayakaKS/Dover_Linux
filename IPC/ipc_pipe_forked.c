#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

void main(){
    int fd[2];
    char buf[20];
    char data[20];

    if(pipe(fd)==0)
     printf("Pipe created successfully\n");
    if(fork() == 0){
        printf("parent writing to pipe\n");
        sprintf(data,"Hai boss :)\n");
        write(fd[1],data,strlen(data));
    }
    else{
        printf("Child reading data from pipe\n");
        read(fd[0],buf,14);
        printf("%s",buf);
    }
    sleep(10);
}

