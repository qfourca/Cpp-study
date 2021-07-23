#include <iostream>

template <typename tem1>
void function1(tem1 parm)
{
}
template <typename tem2>
void function2(const tem2 &parm)
{
}
template <typename tem3>
void function3(tem3 &parm)
{
}
template <
    int main(int argc, char *argv[])
{
    //템플릿 타입 추론 도중에 참조 타입의 인수들은 비참조로 취급된다
    int argument = 1;
    function1(argument); //컴파일 과정에서 컴파일러는 argument를 이용해
                         //두가지 타입을 추론해낸다
                         //하나는 T의 타입 이고 하나는 tem1의 타입이다
                         //이 둘의 타입이 다른 경우가 많다
                         //왜냐하면 arg는 종종 const나 참조자가 붙기 때문이다
    function2(argument); //예를 들어 템블릿이 line8 선언되었을 경우
                         //그리고 이렇게 호출하였을 경우 tem2는
                         //int로 추론되고 parm은 const int&로
                         //추론된다 tem2의 타입은 argument의 타입 뿐만
                         //아니라 parm의 타입에도 의존한다 3가지 종류가 있는데
                         //parm이 포인터나 참조자를 가지고 있으나 universal 참조는 아닐 때
                         //parm이 univisial 참조일 때
                         //parm이 포인터나 참조자를 가지고 있지 않을 때
    //예1 parm이 포인터 또는 참조형이지만 universal 참조는 아닌경우
    //만약 argument 부분이 참조형이라면 참조 부분을 무시한다
    int x = 27;
    const int cx = x;
    const int &rx = x;
    function3(cx);  //tem3는 int형으로 parm의 자료형은 int&로 추론된다
    function3(cx); //tem3는 const int parm의 의 자료형은 const int&로 추론된다
    function3(rx); //tem3는 const int parm의 자료형은 const int&로 추론된다
                   //rx는 참조형이지만 tem3는 비참조로 추론되다

    //std::cout << argument << std::endl;
    return 0;
}