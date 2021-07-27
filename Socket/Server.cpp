#include "Server.h"
ServerSock serverSock;
ClientSock clientSock;
char sendBuffer[BUFSIZ];
char recieveBuffer[BUFSIZ];
void tempFunction()
{
    InputDataInsendBuffer("send.txt", sendBuffer);
    serverSock.SocketDefine();
    serverSock.SockAdressClear();
    serverSock.BindAndListenSocketInPort(PORT);

    while (true)
    {
        clientSock.thisSocket = accept(serverSock.thisSocket, clientSock.ReturnSockAdressP(), &clientSock.adressLen);
        printf("----------------------------------------------------\n");
        //printf("%d\n", clientAdress.sin_addr.s_addr);
        if (read(clientSock.thisSocket, recieveBuffer, sizeof(recieveBuffer)) > 0)
            printf("%s", recieveBuffer);
        printf("----------------------------------------------------\n");
        if (write(clientSock.thisSocket, sendBuffer, strlen(sendBuffer) + 1) == -1)
            printf("Failed to send message\n");
        else
            printf("data sended sucessfully!\n");
        close(clientSock.thisSocket);
    }
}

int InputDataInsendBuffer(const char *fileName, char *buffer)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("File Reading Error");
        return 0;
    }
    for (int i = 0; i < BUFSIZ; i++)
    {
        fscanf(file, "%c", &buffer[i]);
    }
    fclose(file);
    return 1;
}
void CommandReader()
{
    char command[128];
    for (;;)
    {
        std::cin >> command;
        if (!strcmp(command, "end"))
        {
            close(serverSock.thisSocket);
            exit(0);
        }
    }
}
