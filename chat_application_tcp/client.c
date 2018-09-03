//Client-side Code for Chat.
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
int main()
{
    //Create a socket
    int net_sock;
    net_sock=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server_address;

    //Specify the server address and port
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //Connect to the IP
    int connection_status = connect(net_sock,(struct sockaddr *)&server_address,sizeof(server_address));

    //Error checking for connection
    if(connection_status == -1)
        printf("There is a error in connection ");
    char server_response[256];
    char arr[256];

    //Receive and send messages with server
    while(strcmp(arr,"exit"))
    {
        printf("\nMessage: ");
        scanf("%[^\n]%*c",arr);
        send(net_sock,arr,sizeof(arr),0);
        recv(net_sock, &server_response, sizeof(server_response),0);
        printf("Message: %s", server_response);
    }
    close(net_sock);
    return 0;
}
