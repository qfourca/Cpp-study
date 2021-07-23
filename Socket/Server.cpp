#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <memory.h>
#include <unistd.h>
#include <iostream>
#define PORT 9000
char buffer[BUFSIZ] = "Hello, World";
char sendBuffer[BUFSIZ];

void inputDataInsendBuffer();

int main()
{
    inputDataInsendBuffer();
    int clientSocket, serverSocket;
    struct sockaddr_in clientAddr, serverAddr;
    unsigned int len;
    int n;

    serverSocket = socket(PF_INET, SOCK_STREAM, 0); //소켓을 생성

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT); //연결 요청을 수신할 주소 설정
    //close(serverSocket);

    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        printf("Can not Bind\n");
        return -1;
    } //소켓을 포트에 연결

    if (listen(serverSocket, 5) == -1)
    {
        printf("listen Fail\n");
        return -1;
    } //커널에 개통 요청

    char recieveBuffer[BUFSIZ];
    while (true)
    {
        len = sizeof(clientAddr);
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &len);
        //클라이언트 연결 요청 수신
        for (;;)
            if (read(clientSocket, recieveBuffer, sizeof(recieveBuffer)) > 0)
                break;

        //printf("%d", clientSocket);
        //std::cout >> clientAddr.sin_addr.s_addr >> std::endl;
        n = strlen(recieveBuffer);

        write(clientSocket, recieveBuffer, n);
        //클라이언트 요청 서비스 제공
        printf("%s", recieveBuffer);
    }
    close(serverSocket);
    //서버 종료
    return 0;
}

void inputDataInsendBuffer()
{
    FILE *file = fopen("text.txt", "r");
    if (file == NULL)
    {
        printf("파일 입출력 오류");
        exit(1);
    }
    fscanf(file, "%s", sendBuffer);
    fclose(file);
    printf("%c", sendBuffer[0]);
}
