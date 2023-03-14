#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[]){
	printf("P1 code is running\n");
	
	//execl("./execl_p2","1","2","3",NULL);
	execv("./execl_p2",argv);
	printf("P1 code\n");
	return 0;	
}
