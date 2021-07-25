#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <memory.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#define PORT 80
#define MYIP "192.168.35.149"

int InputDataInsendBuffer(char *buffer);
//void WriteLogInTXTFIle(char *Buffer);
int SendMessage(int socket);

char sendBuffer[BUFSIZ];
char recieveBuffer[BUFSIZ];
int main()
{
    InputDataInsendBuffer(sendBuffer);
    int clientSocket, serverSocket;
    struct sockaddr_in serverAddress, clientAdress;
    unsigned int adressLen;

    serverSocket = socket(PF_INET, SOCK_STREAM, 0);

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_addr.s_addr = inet_addr(MYIP);
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

    printf("Server Open! %s:%u\n", MYIP, ntohs(serverAddress.sin_port));
    while (true)
    {
        adressLen = sizeof(clientAdress);
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAdress, &adressLen);
        /*
        for (;;)
            if (read(clientSocket, recieveBuffer, sizeof(recieveBuffer)) > 0)
                break;
                */

        //recv()
        /*
        if (read(clientSocket, recieveBuffer, sizeof(recieveBuffer)) > 0)
        {
            InputDataInsendBuffer()
            break;
        }*/
        int sendTemp;
        if (sendTemp = write(clientSocket, sendBuffer, strlen(sendBuffer) + 1) == -1)
            printf("Failed to send message\n");
        else
            printf("data sended sucessfully!%d\n", sendTemp);
        close(clientSocket);
    }
    close(serverSocket);
}
/*
int WriteLogInTXTFILE(char *buffer)
{
    int file;
    int n;
    file = open("recieve.txt", O_RDWR);
    if (file == -1)
    {
        printf("open error : ");
        return 0;
    }
    n = write(file, buffer, sizeof(buffer) + 1);
    close(file);
}*/

int InputDataInsendBuffer(char *buffer)
{
    FILE *file = fopen("send.txt", "r");
    if (file == NULL)
    {
        printf("File Reading Error");
        return 0;
    }

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
    return 1;
}