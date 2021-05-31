#include "Calculate.h"
#include <bitset>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
bitset<32> binCalculate::InputDecToBin(int input)
{
    bool isNegtive = input < 0;
    bitset<32> ret;
    ret.reset();
    stack<bool> ST;
    bool temp;
    while (input != 1 && input != 0)
    {
        temp = input % 2;
        input /= 2;
        ST.push(temp);
    }
    ST.push(input);
    for (int i = ST.size() - 1; i > -1; i--)
    { 
        ret.set(i, ST.top());
        ST.pop();
    }
    return isNegtive ? ret.flip() : ret;
}

bitset<32> binCalculate::InputDecToBin(float input)
{
    bitset<32> z = InputDecToBin(int(input));
    int i = 32;
    for(;i>0;i--)
    {
        if(z[i]==true)
            break;
    }
    z[i] = false;
    z = IEEEConter(input, z);
    bitset<32> x = InputDecToBin(127 + i);
    bitset<32> ret;
    ret.reset();
    for(int j = 23;i<31;i++)
        ret[i] = x[i-23];
    i = 32;
    for(;i>0;i--)
    {
        if(z[i]==true)
            break;
    }
    for(int j = 22;j>=0;j--)
    {
        ret[j] = z[i];
        i--;
    }
    cout << ret;
    return ret;
}
void binCalculate::printBin(bitset<32> ans)
{
    cout << ans << endl;
}

int binCalculate::returnDec(bitset<32> input)
{
    int ret = 0;
    for(int i = 0;i<32;i++)
    {
        ret += input[i] * (1<<i);
    }
    return ret;
}
bitset<23> binCalculate::InputDecAfPointToBin(float input)
{
    bitset<23> ret;
    ret.reset();
    stack<bool> ST;
    while (input != 0.0)
    {
        input *= 2;
        if(input>1)
        {
            ST.push(true);
            input-=1;
        }
        else
            ST.push(false);
    }
    for (int i = ST.size() - 1; i > -1; i--)
    { 
        ret.set(i, ST.top());
        ST.pop();
    }
    return ret;
}

bitset<32> binCalculate::IEEEConter(float input, bitset<32> z) {
    float floatingPoint = abs((int)input - input);
    int i = 0;
    while(abs((int)floatingPoint - floatingPoint) != 0.0) {
        float newFloatingPoint = floatingPoint * 2;
        z = (z << 1);
        z[0] = int(newFloatingPoint);
        floatingPoint = abs((int)newFloatingPoint - newFloatingPoint);
    }
    return z;
}
