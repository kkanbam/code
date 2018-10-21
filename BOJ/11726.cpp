/*
    20181021
    11726. 2xn 타일링 #DP #틀림

    풀이:
    D[n] = 2xn 타일을 만들 때, 2x1, 1x2 타일을 가지고 만들 수 있는 경우의 수.

    주의:
    1463은 추가 처리가 필요하기 때문에 go안에서 추가 연산을 했음.
    얘는 그럴 필요가 없으므로 D를 사용했음.
*/
#include <iostream>

using namespace std;

int D[1001] = {0, };

int main()
{
        int n, i;
        int temp;
        cin >> n;
        
        D[0] = 1;
        D[1] = 1;
        
        for (i = 2; i <= n; i++) {
            D[i] = D[i-2] + D[i-1]; // D[n]을 만드는 경우의 수는 D[i-2] + D[i-1]
            D[i] %= 10007;
        }
        
        cout << D[n] << '\n';
}
