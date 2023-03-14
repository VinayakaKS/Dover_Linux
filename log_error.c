#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <error.h>

void main(){
	int fd;
	char path[]={"error_log.txt"};
	close(1);
	fd = open(path,O_RDWR);	
	printf("1");
}
