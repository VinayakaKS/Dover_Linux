       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <stdio.h>
       #include <unistd.h>
#include <string.h>

void main(){
	int fd1, fd2;
	char path[]="/home/vinayakaks/Documents/linux_training/system_programming/log.txt";

	fd1 = open("file1.txt",O_RDWR|O_APPEND|O_CREAT);
	fd2 = open("file2.txt",O_RDWR|O_APPEND|O_CREAT);
	
	printf("%d, %d \n",fd1, fd2);

	//char *buffer;
	//asprintf(&buffer,"%d, %d \n",fd1, fd2);
	
	//int len=write(fd,buffer,1);
}
