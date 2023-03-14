#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void main(){
	int fd= open("race_text.txt",O_RDWR|O_APPEND|O_SYNC);
	char buf[1];
	buf[0]='B';

	for(int i=0;i<100;i++){
		write(fd,buf,1);
	}
}
