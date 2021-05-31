#include "Calculate.h"
#include <bitset>
#include <stack>
#include <iostream>

using namespace std;

bitset<2> SubAdder::fullAdderCore(bool a, bool b, bool x)
{
    bitset<2> ret;        // out round
    bool T = (a ^ b) ^ x; // core
    ret.set(0, T);
    T = ((a & b) ^ ((a ^ b) & x));
    ret.set(1, T);
    return ret;
}

bitset<32> SubAdder::fullAdder(bitset<32> OPrator,bitset<32> OPrand)
{
    bitset<32> ret;
    bool round = false;
    for (int i = 0; i < 32; i++)
    {
        bitset<2> OutRound = fullAdderCore(OPrator[i], OPrand[i], round);
        ret.set(i, OutRound[0]);
        round = OutRound[1];
    }
    return ret;
}
