#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>

int main()
{
     int sockfd;
     char buffer[1024];

     struct sockaddr_in server_addr,client_addr;
     socklen_t len = sizeof(client_addr);

     sockfd = socket(AF_INET, SOCK_DGRAM, 0);
     if (sockfd == -1)
     {
        printf("Socket creation failed!\n");
        return 1;
     }
     printf("Socket creation successfully.\n");

     server_addr.sin_family = AF_INET;
     server_addr.sin_port = htons(8080);
     server_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
       printf("Bind failed!\n");
       return 1;
    }
    printf("Bind successfully\n");
    printf("Server is waiting...\n");

    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &len);

    printf("Client says: %s\n", buffer);

    strcpy(buffer, "Hello Client!");

    sendto(sockfd, buffer, strlen(buffer) + 1, 0, (struct sockaddr *)&client_addr, len);

    close(sockfd);
    return 0;
}
