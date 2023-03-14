#include <stdio.h>

void main(int argc, char *argv[]){
	if(strcmp(argv[1],"sum")==0)
		printf("sum is %d",(atoi(argv[2])+atoi(argv[3])));
	else if(strcmp(argv[1],"sub")==0)
		printf("diff is %d",(atoi(argv[2])-atoi(argv[3])));
}
