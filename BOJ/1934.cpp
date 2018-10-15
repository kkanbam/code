/*
        20181015
        1934. 최소공배수 #수학

        최소공배수 공식을 이용하여 푸는 문제
*/
#include <iostream>

using namespace std;

int gcd((nt a, int b);
int lcm(int a, int b);

int main()
{
    int tc, a, b;

    cin >> tc;
    
    for (int i = 0; i < tc; i++) {
        cin >> a >> b;
        cout << lcm(a, b) << endl;
    }
    
    return 0;
}

int gcd(int a, int b)
{
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a*b) / gcd(a, b);    
}
