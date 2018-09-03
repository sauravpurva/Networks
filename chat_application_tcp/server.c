//Server-side Code for Chat.

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
int main()
{
    //Create a socket
    char server_message[256];
	int server_socket;
    server_socket=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    //Specify the server address and port
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //Bind the socket to the IP
    bind(server_socket,(struct sockaddr*) &server_address ,sizeof(server_address));

    //Listen to client connections
    listen(server_socket,5);

    int client_socket;
    //Accept client
    client_socket=accept(server_socket,NULL,NULL);
    char arr[256];
    while(strcmp(arr,"exit"))
    {
        recv(client_socket, &server_message, sizeof(server_message),0);
        printf("\nMessage: %s",server_message);
        printf("\nMessage: ");
        scanf("%[^\n]%*c",arr);
        send(client_socket,arr,sizeof(arr),0);
    }
    close(server_socket);
	return 0;
}
