#include "common.h"
IN_ADDR GetDefaultMyIP()
{
    char localhostname[MAX_PATH];
    IN_ADDR addr = { 0, };
    if (gethostname(localhostname, MAX_PATH) == SOCKET_ERROR)
    {
        return addr;
    }
    HOSTENT* ptr = gethostbyname(localhostname);
    while (ptr && ptr->h_name)
    {
        if (ptr->h_addrtype == PF_INET)
        {
            memcpy(&addr, ptr->h_addr_list[0], ptr->h_length);
            break;
        }
        ptr++;
    }
    return addr;
}
void ViewLocalHostIPv4()
{
    char localhostname[MAX_PATH];
    IN_ADDR addr = { 0, };

    if (gethostname(localhostname, MAX_PATH) == SOCKET_ERROR)//ȣ��Ʈ �̸� ������
    {
        return;
    }
    HOSTENT* ptr = gethostbyname(localhostname);//ȣ��Ʈ ��Ʈ�� ������
    while (ptr && ptr->h_name)
    {
        if (ptr->h_addrtype == PF_INET)//IPv4 �ּ� Ÿ���� ��
        {
            for (int index = 0; ptr->h_addr_list[index]; index++)
            {
                memcpy(&addr, ptr->h_addr_list[index], ptr->h_length);//�޸� ����
                printf("%s\n", inet_ntoa(addr));
            }
        }
        ptr++;
    }
}
