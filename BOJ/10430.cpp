/*
        20181012
        10430. 나머지 #수학

        나머지 정리에서 +, *가 성립하는 규칙을 이용해서 푸는 문제임
        (a + b) % c = (a % c + b % c) % c
        (a * b) % c = (a % c * b % c) % c
*/
#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    
    cin >> a >> b >> c;
    
    cout << (a+b)%c << endl;
    cout << (a%c+b%c)%c << endl;
    cout << (a*b)%c << endl;
    cout << (a%c*b%c)%c << endl;
}
