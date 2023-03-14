#include <stdio.h>
#include <stdlib.h>

void main(){
	char *pint = NULL;
	  
	pint = (char *)malloc(5*sizeof(char));
	printf("%p\n",pint);
	printf("%p\n",(pint+5));
/*
	for(int count=0;count<10;count++){
		pint[count] = count;
		printf("%d\n",pint[count]);
	}
*/
	pint = (char *)realloc(pint,2*sizeof(char));
	printf("%p\n",pint);
	printf("%p\n",(pint+2));
/*	
for(int count=10;count<16;count++){
		pint[count] = count;
		printf("%d\n",pint[count]);
	}
*/
	
}
