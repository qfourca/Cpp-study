#include <bitset>
#include <stack>
#include <iostream>
#include <string>
#include <cmath>
#include "Calculate.h"

void printFloating(float number) {
    float floatingNumber = abs((int)number - number);
printf("%f\n", floatingNumber);

    while(floatingNumber >= 0) {
        float newNumber = floatingNumber * 2;
        printf("%f\n", newNumber);
        while(1);
        floatingNumber = abs((int)newNumber - floatingNumber);
    }
}

int main()
{
    printFloating(3.14);
    binCalculate bincal;
    SubAdder add;
    int* a = new int;
    int* b = new int;
    std::cin >> *a >> *b;
    bitset<32> OPR = bincal.InputDecToBin(*a);
    bitset<32> OPA = bincal.InputDecToBin(*b);
    delete a, b;
    bitset<32> ans = add.fullAdder(OPR,OPA);
    bincal.printBin(ans);
    std::cout << bincal.returnDec(ans) << std::endl;
    return 0;


    /*
    bitset<10> bit;
    // 전체 비트를 0으로 리셋한다.
    bit.reset();
    cout << "bit.reset() :: " <<  bit << endl;
 
    // 전체 비트를 1로 셋팅한다.
    bit.set();
    cout << "bit.set() :: " << bit << endl;
 
    // 비트셋으로 선언한 bit의 할당된 수를 구한다
    int size = (int)bit.size();
    cout << "bit.size() :: " << size << endl ;
 
    // 비트셋중 하나라도 1이면 1을 반환, 모두 0이면 0을 반환한다.
    // 현재는 bit.set()로 인해 모두 1이다.
    cout << "bit.any() :: " << bit.any() << endl;
 
    // 0으로 리셋
    bit.reset();
    cout << "bit.reset() :: " << bit.reset() << endl;
    // 현재는 0으로 모두 리셋이 되었으니 0이 출력된다.
    cout << "bit.any() :: " << bit.any() << endl;
 
    // 4번째 비트 반전
    bit.flip(3); 
 
    // 하나라도 1이면 bit.any()는 1이되니 bit.none()는 0이된다.
    cout << "bit.none() :: " << bit.none() << endl << endl;
 
    // 현재 비트 구성 확인
    cout << "bit state :: " << bit << endl;
 
    // 첫번째 비트는 true, 네번째 비트는 false 할당
    bit.set(0, true);
    bit.set(3, false);
 
    cout << "bit.set(0, true), bit.set(3, false); " << bit << endl;
 
 
    // 첫번째 비트 검사
    cout << "bit.test(0) :: " << bit.test(0) << endl;
 
    // 다섯번째 비트 검사(배열형식으로도 가능하다.)
    cout << "bit[4] :: " << bit[4] << endl;
 
    // 현재 비트 출력
    cout << "bit state :: " << bit;
    void inputDecToBin1(int a)
    {
        OPrator.reset();
        stack<bool> ST;
        bool temp;
        int i = 0;
        for(i = 0; a != 1 && a != 0; i++)
        {
            cout << a << " ";
            temp = a%2;
            a/=2;
            OPrator.set(i,temp);
            cout << temp <<endl;
        }
        OPrator.set(i,1);
    }*/
}
