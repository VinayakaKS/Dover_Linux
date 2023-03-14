#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>

void main(int argc, char *argv[]){
    int fd;
    size_t len;
    char *addr;

    fd = shm_open("/shm1",O_CREAT|O_RDWR,0660);
    len = strlen(argv[1]);
    ftruncate(fd,len);
    addr = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    close(fd);
    memcpy(addr,argv[1],len);
}