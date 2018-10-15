/*
        20181015
        1929. 소수 구하기 #수학

        풀이:
        1. 에라토스테네스의 체를 이용하여 prime 배열에 자연수 n까지 소수를 모두 저장한다.
        2. m 이상인 소수만 출력한다.

        주의할 점:
        1. 출력 시에 endl을 붙이면 시간 초과가 발생한다. (대신 " "을 이용한다)
        2. 인덱스를 조심하자.
*/
#include <iostream>

using namespace std;

int main()
{
    // primes until m, print after n
    int prime[1000000];
    bool check[1000001];
    int pn = 0;
    int m, n; // n is bigger number

    cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        check[i] = false; // not erased (yet) = prime number
    }

    for (int i = 2; i <= n; i++) {
        if (check[i] == false) { // not erased?! prime number!!!
            prime[pn++] = i;
            for (int j = i+i; j <= n; j += i) {
                check[j] = true;
            }
        }
    }

    for (int i = 0; i < pn; i++) {
        if (prime[i] >= m) cout << prime[i] << " ";
    }
}
