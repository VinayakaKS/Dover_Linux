#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	printf("P2 code is getting executed now\n");	
	for(int i=0;i<argc;i++){
		printf("%s\n",argv[i]);
	}
return 0;	
}
