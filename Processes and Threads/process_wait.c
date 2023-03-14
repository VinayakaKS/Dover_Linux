#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void main(){
	pid_t cpid;
	int status;

	cpid = fork();
	if(cpid <0){
		printf("Eror creating the process\n");
	}
	else if(cpid==0){
		printf("Child sleeping for 3 secs with pid - %d\n",getpid());
		sleep(15);
		exit(1);
	}
	else{
		printf("Parent executing before wait\n");
		//cpid = wait(NULL);
		cpid = wait(&status);
		printf("Parent executing after the wait with status is %d with pid as %d\n",status,cpid);
	}
}
