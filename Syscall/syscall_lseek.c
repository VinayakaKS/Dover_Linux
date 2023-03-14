#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void main(){
	int fd,pos;
	fd = open("log.txt",O_RDWR);
	
	pos = lseek(fd,0,SEEK_SET);
	printf("%d\n",pos);
	pos = lseek(fd,0,SEEK_END);
	printf("%d\n",pos);
	pos = lseek(fd,2,SEEK_END);
	printf("%d\n",pos);

	if(close(fd))
		printf("Error closing file\n");
	else
		printf("File closed successfully\n");
}
