       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <unistd.h>

void main(){
int len;
char buffer[3]={'H','i','\n'};
len=write(1,buffer,2);
}
