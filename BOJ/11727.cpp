/*
    20181021
    11727. 2xn 타일링 2 #DP

    11726과 상동. 단지 타일이 2x2가 추가되어, n-2를 만들 수 있는 갯수가 두 배로 늘어난 것.
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
            D[i] = (2*D[i-2]) + D[i-1];
            D[i] %= 10007;
        }
        
        cout << D[n] << '\n';
}
