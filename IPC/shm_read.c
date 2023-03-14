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
    struct stat len;
    char *addr;

    fd = shm_open("/shm1",O_RDONLY,0);
    fstat(fd,&len);
    addr = mmap(NULL,len.st_size,PROT_READ,MAP_SHARED,fd,0);
    printf("Read from shm - %s\n",addr);
}