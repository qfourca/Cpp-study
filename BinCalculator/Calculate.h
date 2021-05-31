#pragma once
#include <bitset>
#include <stack>
#include <iostream>
#include <string>

using namespace std;

class binCalculate
{
private:
    bitset<23> InputDecAfPointToBin(float a);
    bitset<32> IEEEConter(float input, bitset<32> z);

public:
    bitset<32> InputDecToBin(int a);
    bitset<32> InputDecToBin(float input);
    void printBin(bitset<32>);
    int returnDec(bitset<32>);
};

class SubAdder : public binCalculate
{
private:
    bitset<2> fullAdderCore(bool a,bool b,bool x);

public:
    bitset<32> fullAdder(bitset<32> OPrator,bitset<32> OPrand);
    bitset<32> Subtractor(bitset<32> OPrator, bitset<32> OPrand);
};