#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

void main(){
    int fd;
    char buf[200];
    char *path = "/tmp/myfifo";
    mkfifo(path,0660);
    fd = open(path,O_WRONLY);

    while(1){
        printf("Write \n");
        fgets(buf,20,stdin);
        write(fd,buf,strlen(buf)+1);
    }
}