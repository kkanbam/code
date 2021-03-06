/*
    20181020
    1463. 1로 만들기 #DP #틀림 #중요

    풀이:
    go(n): n->1로 만드는 가장 작은 경우의 수를 리턴하는 함수

    주의:
    go(n)을 넣어야 할 부분에 죄다 D[n]을 넣었음. 매우 주의해야 함. (심지어 함수 호출부에서도 D[n]를 넣었음. 주의할 것)
    로직을 이해하고, exception (예를 들어, 1이 입력으로 들어왔을 때 0리턴) 같은 부분 처리를 유념할 것
*/
#include <iostream>

using namespace std;

int D[1000000] = {0, }; // 10^6까지 입력 가능

int go(int n)
{   
    int temp;
    if (n == 1) return 0;
    if (D[n] > 0) return D[n]; // 만약 해당 값이 0 이상이라면 이미 계산된 값임
    D[n] = go(n-1) + 1; // Case A: 가장 작게 줄어드는 케이스이지만, 기본으로 계산해두는 것임. n-1에 대해 경우의 수를 계산하고, 1을 빼는 것으로 처리함.
    if (n % 2 == 0) {   // 그런데 만약 n이 2로 나누어 떨어지는 경우
        temp = go(n/2) + 1; // 2로 나눈 경우를 추가하고, n/2에 대해 경우의 수 계산
        if (temp < D[n]) D[n] = temp; // 계산한 결과 temp가 -1 케이스랑 비교해서 더 작으면 교체함
    }
    if (n % 3 == 0) {
        temp = go(n/3) + 1;
        if (temp < D[n]) D[n] = temp;
    }
    return D[n]; // 계산한 값을 리턴함
}

int main()
{
    int n;
    cin >> n;
    
    cout << go(n) << '\n'; // D[n]을 읽는 부분은 go 함수 안에 포함되어 있으므로 신경쓰지 않아도 됨
}
