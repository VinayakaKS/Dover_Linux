#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void main(){
	pid_t id;
	id = fork();
	if(id<0){
		printf("Process not created\n");
		exit(-1);
}
	else if(id>0)
{
		printf("Parent process ID- %d\n",getpid());
		sleep(2);
}
	else if(id==0){
		printf("child process id - %d\n",getpid());
		printf("Parent process id - %d\n",getppid());
	}

		
}
