#pragma once
#include "SockClass.h"
#define PORT 80
#define MYIP "192.168.35.149"

extern void tempFunction();
int InputDataInsendBuffer(const char *fileName, char *buffer);
int SendMessage(int socket);
void CommandReader();
