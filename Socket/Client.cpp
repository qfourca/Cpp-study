#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <memory.h>
#include <unistd.h>

#define PORT 9000
#define IPADDR "127.0.0.1"

int main()
{
    int clientSocket;
    struct sockaddr_in clientAddr;
    int len;
    int n;

    char recieveBuffer[BUFSIZ];

    clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    //소켓을 생성하기

    memset(&clientAddr, 0, sizeof(clientAddr));
    clientAddr.sin_addr.s_addr = inet_addr(IPADDR);
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(PORT);
    //연결할 서버의 주소 설정

    if (connect(clientSocket, (struct sockaddr *)&clientAddr, sizeof(clientAddr)) == -1)
    {
        printf("Can not connect\n");
        close(clientSocket);
        return -1;
    } //소켓을 서버에 연결
    for (;;)
    {
        if ((n = read(clientSocket, recieveBuffer, sizeof(recieveBuffer))) > 0)
        {
            printf("%u :%s\n", clientAddr.sin_port, recieveBuffer);
            break;
        }
    }

    close(clientSocket);
    //소켓 연결을 종료
}