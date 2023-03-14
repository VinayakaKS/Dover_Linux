#include <stdio.h>
#include <stdlib.h>

extern char **environ;
void func1(void);
void main(int argc, char * argv[]){
	char **ep;
	
	for(ep = environ;*ep!=NULL;ep++){
		printf("%s\n",*ep);
	}
	printf("\nPATH = %s \n",getenv("PATH"));

putenv("AUTHOR=VINAYAKA_KS");
printf("Author is %s\n",getenv(argv[1]));
func1();
printf("Arg[0] is  %s \n",argv[0]);
}

void func1()
{
	printf("\nAUTHOR = %s \n",getenv("AUTHOR"));
}
