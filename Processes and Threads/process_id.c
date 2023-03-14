#include <unistd.h>
#include <stdio.h>


void main(){
	printf("pID - %d, ppID - %d", getpid(),getppid());
}
