#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void main(){
	pid_t cpid1,cpid2;
	int status;

	cpid1 = fork();
	if(cpid1 <0){
		printf("Eror creating the process\n");
	}
	else if(cpid1==0){
		printf("Child 1 pid - %d\n",getpid());
		sleep(3);
		exit(1);
	}
	else{	
		cpid2=fork();
		if(cpid2 <0){
			printf("Eror creating the process\n");
		}
		else if(cpid2==0){
			printf("Child 2 pid - %d\n",getpid());
			sleep(3);
			exit(1);
		}
		
		printf("Parent executing before wait\n");

		//cpid1 = wait(&status);
		cpid1 = waitpid(cpid1,&status,WNOHANG);
		printf("exited %d with status %d\n",cpid1,status);

		//cpid1 = wait(&status);
		cpid2 = waitpid(cpid2,&status,WNOHANG);
		printf("exited %d with status %d\n",cpid2,status);

		printf("Exit now\n");
	}
}
