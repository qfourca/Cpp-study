#include "common.h"
#define PORT_NUM      10200
#define BLOG_SIZE     5
#define MAX_MSG_LEN   256
SOCKET SetTCPServer(short pnum, int blog);//��� ���� ����
void EventLoop(SOCKET sock);//Event ó�� Loop

int main()
{
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);//���� �ʱ�ȭ	
    SOCKET sock = SetTCPServer(PORT_NUM, BLOG_SIZE);//��� ���� ����
    ViewLocalHostIPv4();
    if (sock == -1)
    {
        perror("��� ���� ����");
    }
    else
    {
        EventLoop(sock);
    }
    WSACleanup();//���� ����ȭ
    return 0;
}

SOCKET SetTCPServer(short pnum, int blog)
{
    SOCKET sock;
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//���� ����
    if (sock == -1)
    {
        return -1;
    }

    SOCKADDR_IN servaddr = { 0 };//���� �ּ�
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr = GetDefaultMyIP();
    servaddr.sin_port = htons(PORT_NUM);

    int re = 0;
    //���� �ּҿ� ��Ʈ��ũ �������̽� ����
    re = bind(sock, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if (re == -1)
    {
        return -1;
    }

    re = listen(sock, blog);//�� �α� ť ����
    if (re == -1)
    {
        return -1;
    }
    return sock;
}

SOCKET  sock_base[FD_SETSIZE];
HANDLE hev_base[FD_SETSIZE];
int cnt;

HANDLE AddNetworkEvent(SOCKET sock, long net_event)
{
    HANDLE hev = WSACreateEvent();

    sock_base[cnt] = sock;
    hev_base[cnt] = hev;
    cnt++;

    WSAEventSelect(sock, hev, net_event);
    return hev;
}
void AcceptProc(int index);
void ReadProc(int index);
void CloseProc(int index);
void EventLoop(SOCKET sock)
{
    AddNetworkEvent(sock, FD_ACCEPT);

    while (true)
    {
        int index = WSAWaitForMultipleEvents(cnt, hev_base, false, INFINITE, false);
        WSANETWORKEVENTS net_events;
        WSAEnumNetworkEvents(sock_base[index], hev_base[index], &net_events);
        switch (net_events.lNetworkEvents)
        {
        case FD_ACCEPT: AcceptProc(index); break;
        case FD_READ: ReadProc(index); break;
        case FD_CLOSE: CloseProc(index); break;
        }
    }
    closesocket(sock);//���� �ݱ�
}

void AcceptProc(int index)
{
    SOCKADDR_IN cliaddr = { 0 };
    int len = sizeof(cliaddr);
    SOCKET dosock = accept(sock_base[0], (SOCKADDR*)&cliaddr, &len);

    if (cnt == 3)
    {
        printf("�濡 �� ���� %s:%d �������� ���Ͽ���!\n",
            inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
        closesocket(dosock);
        return;
    }

    AddNetworkEvent(dosock, FD_READ | FD_CLOSE);
    printf("%s:%d-%d�÷��̾� ����\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port), cnt-1);
    char smsg[MAX_MSG_LEN];
    itoa(cnt - 1, &smsg, 10);

    send(sock_base[cnt-1], smsg, MAX_MSG_LEN, 0);
}

void ReadProc(int index)
{
    char msg[MAX_MSG_LEN];
    recv(sock_base[index], msg, MAX_MSG_LEN, 0);

    SOCKADDR_IN cliaddr = { 0 };
    int len = sizeof(cliaddr);
    getpeername(sock_base[index], (SOCKADDR*)&cliaddr, &len);
    printf("%s\n",msg);
    char smsg[MAX_MSG_LEN];
    sprintf(smsg, "%s-%d:%s", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port), msg);

    for (int i = 1; i < cnt; i++)
    {
        send(sock_base[i], smsg, MAX_MSG_LEN, 0);
    }
}


void CloseProc(int index)
{
    SOCKADDR_IN cliaddr = { 0 };
    int len = sizeof(cliaddr);
    getpeername(sock_base[index], (SOCKADDR*)&cliaddr, &len);
    printf("[%s:%d]  �� ����~\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

    closesocket(sock_base[index]);
    WSACloseEvent(hev_base[index]);

    cnt--;
    sock_base[index] = sock_base[cnt];
    hev_base[index] = hev_base[cnt];

    char msg[MAX_MSG_LEN];
    sprintf(msg, "[%s:%d]�� ����~\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
    for (int i = 1; i < cnt; i++)
    {
        send(sock_base[i], msg, MAX_MSG_LEN, 0);
    }
}