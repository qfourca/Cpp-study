#include "common.h"

void RecvThreadPoint(void* param);
int main()
{
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);//���� �ʱ�ȭ	

    SOCKET sock;
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//���� ����
    if (sock == -1)
    {
        return -1;
    }

    SOCKADDR_IN servaddr = { 0 };//���� �ּ�
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    servaddr.sin_port = htons(PORT_NUM);

    int re = 0;
    re = connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr));//���� ��û
    if (re == -1)
    {
        return -1;
    }
    _beginthread(RecvThreadPoint, 0, (void*)sock);
    char msg[MAX_MSG_LEN] = "";
    while (true)
    {
        gets_s(msg, MAX_MSG_LEN);
        send(sock, msg, sizeof(msg), 0);//�۽�
        if (strcmp(msg, "exit") == 0)
        {
            break;
        }
    }
    closesocket(sock);//���� �ݱ�    

    WSACleanup();//���� ����ȭ
    return 0;
}
void RecvThreadPoint(void* param)
{
    SOCKET sock = (SOCKET)param;
    char msg[MAX_MSG_LEN];

    SOCKADDR_IN cliaddr = { 0 };
    int len = sizeof(cliaddr);

    while (recv(sock, msg, MAX_MSG_LEN, 0) > 0)
    {
        printf("%s\n", msg);
    }
    closesocket(sock);
}