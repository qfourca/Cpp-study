#define _CRT_SECURE_NO_WARNINGS
#include "Serverconection.h"
#include "Header.h"

int main()
{
	Setting();
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			DrawCharacter(i+1, j+1, Character[i][j]); // ĳ���͸� �׸��� ���
	
	myCursor.x = 1;
	myCursor.y = 2;

	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);//���� �ʱ�ȭ	

	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//���� ����
	if (sock == -1) { return -1; };

	SOCKADDR_IN servaddr = { 0 };//���� �ּ�
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
	servaddr.sin_port = htons(PORT_NUM);

	int re = 0;
	re = connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr));//���� ��û
	if (re == -1) { return -1; }
	_beginthread(RecvThreadPoint, 0, (void*)sock);
	char msg[MAX_MSG_LEN] = "";

	DrawBorder(myCursor.x, myCursor.y, RED);
	for (;;)
	{
		//gets_s(msg, MAX_MSG_LEN);
		//send(sock, msg, sizeof(msg), 0);//�۽�
		//if (strcmp(msg, "exit") == 0) { break; }
		if (GetAsyncKeyState(VK_LEFT) && myCursor.x > 1)
		{
			DrawBorder(myCursor.x, myCursor.y, isColor[myCursor.x - 1][myCursor.y - 1] ? WWHITE : WBLACK);
			DrawBorder(--myCursor.x, myCursor.y, RED);
			Sleep(AFTERINPUTKEYSTOP);
		}
		if (GetAsyncKeyState(VK_RIGHT) && myCursor.x < 8)
		{
			DrawBorder(myCursor.x, myCursor.y, isColor[myCursor.x - 1][myCursor.y - 1] ? WWHITE : WBLACK);
			DrawBorder(++myCursor.x, myCursor.y, RED);
			Sleep(AFTERINPUTKEYSTOP);
		}
		if (GetAsyncKeyState(VK_UP) && myCursor.y < 8)
		{
			DrawBorder(myCursor.x, myCursor.y, isColor[myCursor.x - 1][myCursor.y - 1] ? WWHITE : WBLACK);
			DrawBorder(myCursor.x, ++myCursor.y, RED);
			Sleep(AFTERINPUTKEYSTOP);
		}
		if (GetAsyncKeyState(VK_DOWN) && myCursor.y > 1)
		{
			DrawBorder(myCursor.x, myCursor.y, isColor[myCursor.x - 1][myCursor.y - 1] ? WWHITE : WBLACK);
			DrawBorder(myCursor.x, --myCursor.y, RED);
			Sleep(AFTERINPUTKEYSTOP);
		}
		if (GetAsyncKeyState(VK_SPACE) && Character[myCursor.x-1][myCursor.y-1] != -1 && ((Character[myCursor.x - 1][myCursor.y - 1] > 15) == myColorIsWhite))
		{
			DrawBorder(myCursor.x, myCursor.y, AQUA);
			CanIGo(myCursor.x, myCursor.y);
			int willSendServerInfo = CharacterMovement(myCursor.x, myCursor.y);
			if (willSendServerInfo == 1) { goto out; }
			itoa(willSendServerInfo, &msg, 10);
			send(sock, msg, sizeof(msg), 0);
			DrawBorder(myCursor.x, myCursor.y, RED);
			Sleep(AFTERINPUTKEYSTOP);
		out:;
		}
	}
	closesocket(sock);//���� �ݱ�    
	WSACleanup();//���� ����ȭ
	return 0;
}