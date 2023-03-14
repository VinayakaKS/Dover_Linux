#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(){
	int fd = open("file_shared.txt",O_RDWR);
	int cpid=fork();
	char buf[3];
	if(cpid < 0){
		printf("Error opening file\n");
	}
	else if(cpid>0){
		read(fd,buf,3);
		printf("%s\n",buf);
		wait(NULL);
		printf("Read complete\n");
	}
	else{
		read(fd,buf,3);
		printf("%s\n",buf);
		exit(1);
	}
}
