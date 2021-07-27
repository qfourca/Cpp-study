#include <stdio.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <memory.h>
#include <fcntl.h>
#include <unistd.h>
#include <thread>
#include <string>
#include <future>
#define PORT 80
#define MYIP "192.168.35.149"

class Sock
{
protected:
    sockaddr_in thisSocketAdress;

public:
    unsigned int adressLen = sizeof(thisSocketAdress);
    int thisSocket;
    void SockAdressClear();
    void SocketDefine();
};

class ClientSock : public Sock
{
public:
    int AcceptConnection(int serverSocket);
    sockaddr *ReturnSockAdressP();
};

class ServerSock : public Sock
{
private:
public:
    int BindAndListenSocketInPort(unsigned int portNum);
};
