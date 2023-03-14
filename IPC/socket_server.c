#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<unistd.h>

#define BUFFER_SIZE 128
#define SOCKET_NAME "/tmp/DemoSocket"

int main(int argc, char *argv[]){

    int ret;
    int connection_socket, data_socket, result;
    int data;
    char buffer[BUFFER_SIZE];

    struct sockaddr_un name;

    //Unlink previously present socket
    unlink(SOCKET_NAME);

    //Create master socket
    connection_socket = socket(AF_UNIX,SOCK_STREAM,0);

    if(connection_socket==-1){
        perror("socket");
        exit(EXIT_FAILURE);
    }

    name.sun_family = AF_UNIX;
    strncpy(name.sun_path,SOCKET_NAME,sizeof(name.sun_path)-1);

    //Bind the socket to the adderess of SOCKET_NAME
    ret=bind(connection_socket,(const struct sockaddr *)&name,sizeof(struct sockaddr_un));

    if(ret == -1){
        perror("Bind error");
        exit(EXIT_FAILURE);
    }
    printf("Bind successful\n");

    //Listen on the socket and can listen from 20 clients
    ret=listen(connection_socket,20);

    if(ret == -1){
        perror("Listen error");
        exit(EXIT_FAILURE);
    }
    printf("Listen successful\n");

    //Main loop for handling connections
    for(;;){
        printf("Waiting in accept() sys call\n");
        data_socket = accept(connection_socket,NULL,NULL);

    if(data_socket == -1){
        perror("Accept error");
        exit(EXIT_FAILURE);
    }
    printf("Connection accepted from client\n");
    result=0;

    //loop to read data from client 
    for(;;){
        memset(buffer,0,BUFFER_SIZE);
        printf("Waiting for data from client\n");
        
        ret=read(data_socket,buffer,BUFFER_SIZE);
        printf("Data from client - %s\n",buffer);

        memcpy(&data,buffer,sizeof(int));
        if(data==0)
            break;
        result+=data;
    }

    memset(buffer,0,BUFFER_SIZE);
    sprintf(buffer,"The sum is %d\n",result);

    //Sending the response
    ret=write(data_socket,buffer,BUFFER_SIZE);

    if(data_socket == -1){
        perror("Send error");
        exit(EXIT_FAILURE);
    }
    //Closing the client handle
    close(data_socket);
    }

    //Closing the master socket
    close(connection_socket);
    unlink(SOCKET_NAME);

    exit(EXIT_SUCCESS);

}

