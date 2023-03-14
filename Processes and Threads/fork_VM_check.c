#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int gdata=10;
void main(){
	int ldata = 100;
	pid_t cpid;

	switch(cpid = fork()){
		case -1: printf("Error creating process\n");
			 break;
		case 0: ldata*=2;
			gdata*=2;
			printf("global - %d, local - %d\n",gdata,ldata);
			sleep(3);
			break;
		default:printf("global - %d, local - %d\n",gdata,ldata);
			sleep(3);
			break;
	}	
}
