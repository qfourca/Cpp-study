#pragma once
#pragma warning(disable : 4996)
#define PORT_NUM    10200
#define MAX_MSG_LEN 256
#define SERVER_IP   "192.168.35.149" //���� IP �ּ�
#include <WinSock2.h>
#include <Windows.h>
#include <process.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#pragma comment(lib,"ws2_32") 
IN_ADDR GetDefaultMyIP();
void RecvThreadPoint(void* param);