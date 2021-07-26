#include "customio.h"
using namespace custom;
void print(...)
{
    int fileObj = open("print.txt", O_APPEND | O_CREAT);
    if (fileObj == -1)
    {
        perror("File open ERROR");
        return;
    }
    printf("%s", buffer);
    write(fileObj, buffer, sizeof(buffer));
    close()
}