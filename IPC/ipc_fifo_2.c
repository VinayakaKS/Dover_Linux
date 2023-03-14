#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

void main(){
    int fd;
    char buf[200];
    char *path = "/tmp/myfifo";
    
    fd = open(path,O_RDONLY);

    while(1){
        read(fd,buf,20);
        printf("FIFO - %s\n",buf);
    }
}