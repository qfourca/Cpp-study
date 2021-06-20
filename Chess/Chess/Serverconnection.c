#include "Serverconection.h"
#include "Header.h"
void RecvThreadPoint(void* param)
{
    SOCKET sock = (SOCKET)param;
    char msg[MAX_MSG_LEN];

    SOCKADDR_IN cliaddr = { 0 };
    int len = sizeof(cliaddr);
    recv(sock, msg, MAX_MSG_LEN, 0);
    if (msg[0] == 49) { myColorIsWhite = false; }
    else { myColorIsWhite = true; }

    //temp == 1? myColorIsWhite = true : myColorIsWhite = false; //½ÅÇö±Ô
 
    while (recv(sock, msg, MAX_MSG_LEN, 0) > 0)
    {  
        strcpy(serverInput, msg);
        int printXY = atoi(msg);
        int i;
        for (i = 0; msg[i] != ':'; i++) {}
        int FX = msg[i + 1] - 48;
        int FY = msg[i + 2] - 48;
        int SX = msg[i + 3] - 48;
        int SY = msg[i + 4] - 48;
        Character[SX - 1][SY - 1] = Character[FX - 1][FY - 1];
        Character[FX - 1][FY - 1] = -1;
        DrawCore(FX, FY, isColor[FX - 1][FY - 1]);
        DrawCore(SX, SY, isColor[SX - 1][SY - 1]);
        DrawCharacter(SX, SY, Character[SX - 1][SY - 1]);
        turnCount++;
    }
    closesocket(sock);
}