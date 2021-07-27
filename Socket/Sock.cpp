#include "SockClass.h"

void Sock::SockAdressClear()
{
    memset(&thisSocketAdress, 0, sizeof(thisSocketAdress));
}
void Sock::SocketDefine()
{
    thisSocket = socket(PF_INET, SOCK_STREAM, 0);
}

int ClientSock::AcceptConnection(int serverSocket)
{
    thisSocket = accept(serverSocket, (struct sockaddr *)&thisSocketAdress, &adressLen);
    return 0;
}
sockaddr *ClientSock::ReturnSockAdressP()
{
    return (struct sockaddr *)&thisSocketAdress;
}

int ServerSock::BindAndListenSocketInPort(unsigned int portNum)
{
    SockAdressClear();
    thisSocketAdress.sin_family = AF_INET;
    thisSocketAdress.sin_port = htons(portNum);
    if ((thisSocketAdress.sin_addr.s_addr = inet_addr(MYIP)) == -1)
    {
        perror("Wrong IP adress");
        exit(1);
    }
    if (bind(thisSocket, (struct sockaddr *)&thisSocketAdress, sizeof(thisSocketAdress)) == -1)
    {
        perror("Can not Bind");
        exit(1);
    }
    if (listen(thisSocket, 5) == -1)
    {
        perror("listen Fail");
        exit(1);
    }
    printf("Server Open! %s:%u\n\n", MYIP, ntohs(thisSocketAdress.sin_port));
    return 0;
}