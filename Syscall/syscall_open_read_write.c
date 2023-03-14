        #include <sys/types.h>
        #include <sys/stat.h>
        #include <fcntl.h>
	#include <error.h>
	#include <unistd.h>
	#include <stdio.h>

void main(){
	int sz_read, sz_write, count, fd;
	count=0;
	char buffer[5];
	char path[] = "read_file.txt";
	fd = open(path,O_RDWR|O_APPEND);

	if(fd<0){
		perror("Error");
		exit(0);
	}

	
		sz_read=read(fd,buffer,1);
		sz_write=write(fd,buffer,sz_read);
		printf("Call %d",count);
		count++;
	

}
