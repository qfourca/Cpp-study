#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <memory.h>
#include <unistd.h>
#include <iostream>
#define PORT 80
#define MYIP "192.168.35.0"

void InputDataInsendBuffer(char *buffer);
int SendMessage(int socket);

char sendBuffer[BUFSIZ];
char recieveBuffer[BUFSIZ];
int main()
{
    InputDataInsendBuffer(sendBuffer);
    int clientSocket, serverSocket;
    struct sockaddr_in serverAddress, clientAdress;
    unsigned int len;
    int n;

    serverSocket = socket(PF_INET, SOCK_STREAM, 0);

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1)
    {
        printf("Can not Bind\n");
        return -1;
    }

    if (listen(serverSocket, 5) == -1)
    {
        printf("listen Fail\n");
        return -1;
    }
    printf("Server Open! port : %u\n", ntohs(serverAddress.sin_port));

    while (true)
    {
        len = sizeof(clientAdress);
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAdress, &len);
        /*
        for (;;)
            if (read(clientSocket, recieveBuffer, sizeof(recieveBuffer)) > 0)
                break;
                */
        n = strlen(sendBuffer);

        if (write(clientSocket, sendBuffer, n) == -1)
            printf("Failed to send message\n");
        else
            printf("data sended sucessfully!\n");
        close(clientSocket);
    }
    close(serverSocket);
}

void InputDataInsendBuffer(char *buffer)
{
    FILE *file = fopen("send.txt", "r");
    if (file == NULL)
        printf("File Reading Error");

    for (int i = 0; i < BUFSIZ; i++)
    {
        fscanf(file, "%c", &buffer[i]);
    }
    /*
    for (int i = 0; i < BUFSIZ; i++)
    {
        printf("%c", buffer[i]);
    }
    */

    fclose(file);
}