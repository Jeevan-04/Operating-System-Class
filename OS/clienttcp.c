#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// Function to handle communication with server
void func(int sockfd) {
    char buff[MAX];
    int n;

    for (;;) {
        bzero(buff, sizeof(buff));
        printf("Enter the string: ");

        // Read input from the user
        n = 0;
        while ((buff[n++] = getchar()) != '\n');

        // Send the input string to the server
        write(sockfd, buff, sizeof(buff));

        // Clear the buffer for receiving server's response
        bzero(buff, sizeof(buff));

        // Receive and print the server's response
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s", buff);

        // Check if the message from the server contains "exit" to end the chat
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Client Exit...\n");
            break;
        }
    }
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

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
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection with the server failed...\n");
        exit(0);
    }
    else
        printf("Connected to the server...\n");

    // Call function to handle communication with server
    func(sockfd);

    // Close the socket
    close(sockfd);
}

