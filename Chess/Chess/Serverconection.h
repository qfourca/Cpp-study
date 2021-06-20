#pragma once
#pragma warning(disable : 4996)
#define WIN32_LEAN_AND_MEAN

#define PORT_NUM    10200
#define MAX_MSG_LEN 256
#define SERVER_IP   "10.80.162.113" //서버 IP 주소
#include <WinSock2.h>
#include <Windows.h>
#include <process.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#pragma comment(lib,"ws2_32") 
void RecvThreadPoint(void* param);