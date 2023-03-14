#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<unistd.h>

#define BUFFER_SIZE 128
#define SOCKET_NAME "/tmp/DemoSocket"

int main(int argc,char *argv[]){

    struct sockaddr_un name;
    int i,ret,data_socket;
    char buffer[BUFFER_SIZE];

    //create a data_socket
    data_socket = socket(AF_UNIX,SOCK_STREAM,0);
    if(data_socket == -1){
        perror("data socket creation error");
        exit(EXIT_FAILURE);
    }
    printf("data socket creation successful\n");

    memset(&name,0,sizeof(struct sockaddr_un));

    name.sun_family=AF_UNIX;
    strncpy(name.sun_path,SOCKET_NAME,sizeof(name.sun_path)-1);

    ret=connect(data_socket,(const struct sockaddr_un *)&name,sizeof(struct sockaddr_un));

    do{
        printf("Enter number to send to the server\n");
        scanf("%d",&i);

        ret=write(data_socket,&i,sizeof(int));
        if(ret == -1){
            perror("write error");
            exit(EXIT_FAILURE);
        }
    printf("write successful with data - %d\n",i);
    }while(i);

    // memset(buffer,0,BUFFER_SIZE);
    // strncpy(buffer,"sum",strlen("sum"));

    ret = read(data_socket,buffer,BUFFER_SIZE);
    if(ret == -1){
        perror("result read error");
        exit(EXIT_FAILURE);
    }
    buffer[BUFFER_SIZE-1]='\0';
    printf("SUM = %s",buffer);

    close(data_socket);
    exit(EXIT_SUCCESS);
}