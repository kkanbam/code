/*
        20181015
        1978. 소수 찾기 #수학

        풀이:
        1. 각 숫자가 소수인지를 판별한다.
        2. 입력된 숫자가 소수이면 소수 카운트를 증가시킨다. 
                - 여기서 소수를 판별하는 알고리즘은 시간복잡도 루트앤.
                - n개의 숫자에 대해 알고리즘을 수행하니, 시간복잡도 빅오 앤루트앤이 된다.
*/
#include <iostream>

using namespace std;

bool isPrime(int n);

int main()
{
    int n;
    int arr[100];
    int pn = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // insert targer numbers
        if (isPrime(arr[i])) pn++;
    }

    cout << pn << endl;

    return 0;
}

bool isPrime(int n)
{
    if (n < 2)
        return false; // excpetion handling
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
