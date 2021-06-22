#pragma once
#pragma warning(disable : 4996)
#include <WinSock2.h>
#include <Windows.h>
#include <process.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#pragma comment(lib,"ws2_32")
#define PORT_NUM      10200
#define BLOG_SIZE       5
#define MAX_MSG_LEN 256
IN_ADDR GetDefaultMyIP();
SOCKET SetTCPServer(short pnum, int blog);//대기 소켓 설정
void AcceptLoop(SOCKET sock);//Accept Loop
void DoIt(void* param); //송수신
//bool isWhiteTurn = true;

char thisCharacter[8][8];
int white;
int black;