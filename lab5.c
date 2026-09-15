#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    int num, prime = 1;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr *)&server_addr,
         sizeof(server_addr));

    listen(server_fd, 5);

    printf("Server waiting...\n");

    client_fd = accept(server_fd, NULL, NULL);

    read(client_fd, &num, sizeof(num));

    if (num <= 1)
        prime = 0;
    else
    {
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                prime = 0;
                break;
            }
        }
    }

    if (prime)
        write(client_fd, "Prime Number", 13);
    else
        write(client_fd, "Not a Prime Number", 19);

    close(client_fd);
    close(server_fd);

    return 0;
}
468 075 102 462 081468 075 102 462 081
