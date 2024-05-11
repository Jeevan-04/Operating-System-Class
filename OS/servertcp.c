#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/socket.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// Function to handle communication with client
void func(int connfd) {
    char buff[MAX];
    int n;

    for (;;) {
        bzero(buff, MAX);

        // Read the message from client
        read(connfd, buff, sizeof(buff));

        // Print client's message
        printf("From client: %s\t To client :", buff);

        // Send client's message back to client
        write(connfd, buff, sizeof(buff));

        // Check if message contains "exit" to end chat
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
}

int main() {
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created...\n");
    bzero(&servaddr, sizeof(servaddr));

    // Assign IP and PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Bind socket to IP and PORT
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded...\n");

    // Listen for incoming connections
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server Listening...\n");
    len = sizeof(cli);

    // Accept incoming connection
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("Server accept failed...\n");
        exit(0);
    }
    else
        printf("Server accepted the client...\n");

    // Call function to handle communication with client
    func(connfd);

    // Close the socket
    close(sockfd);
}

