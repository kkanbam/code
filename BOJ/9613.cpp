/*
	20181015
	9613. GCD합 #수학 #틀림

	풀이:
	모든 수의 쌍을 구한다, 각 쌍에 대해서 gcd를 구해 sum에 누계한다.

	1.
	중간에 j 카운트를 다음과 같이 바꿔줘야 함.
	for (j = 0; j < numcnt-1; j++) {
	원래 j < numcnt까지 했었는데, 이렇게 하지 말고 j < numcnt-1로 해서 그 다음의 k 카운트와 겹치지 않게해야함

	2.
	sum이 overflow가 날 수 있으므로, sum을 저장하는 자료형을 int에서 long int로 바꿔줌.
	int -> long int
*/
#include <iostream>

using namespace std;

int gcd(int a, int b);

int main()
{
    int tc, numcnt, arr[101];
    long int sum = 0;

    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> numcnt;
        
        for (int j = 0; j < numcnt; j++) {
            cin >> arr[j];
        }
        
        int j, k = 0;
        
        for (j = 0; j < numcnt-1; j++) {
            for (k = j+1; k < numcnt; k++) {
                sum += gcd(arr[j], arr[k]);
            }
        }
        
        cout << sum << endl;
        sum = 0;
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
