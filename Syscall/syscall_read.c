#include <unistd.h>
#include <error.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



void main(){

	char buffer[50];
	int sz;
int count=0;
	char path[] = "read_file.txt";

	int fd = open(path,O_RDWR);
	if(fd<0)
	{
		perror("Error:");
		exit (1);
	}
	
		do{
		sz=read(fd,buffer,10);
		printf("Call %d Fd = %d, bytes read = %d",count,fd,sz);
		buffer[sz]='\0';
		printf("The read bytes are : \n%s\n",buffer);
		count++;
		} while(sz!=0);	

}
