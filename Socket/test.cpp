#include <cstring>
#include <iostream>
#include <stdio.h>
template <typename T1>
char *func(T1 first)
{
    return std::to_string(first);
}
int main()
{
    char data[10] = "apple";
    int a = 10;
    //strcpy(data, strcat(data, a));
    printf("%s%s", func(data), func(a));
    //std::cout << "Hello World" << a << "\n";
    return 0;
}
