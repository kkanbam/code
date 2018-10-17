/*
	20181017
	10974. 모든 순열 #브루트포스

	풀이:
	1. vector에 저장
	2. next_permutation을 이용

	주의:
	while 문에서 arr.end()가 아닌 arr.begin()+n 사이즈를 넣어줘야 함
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> arr(8);
	int n, i;

	cin >> n;

	for (i = 0; i < n; i++) 
		arr[i] = i+1;

	do {
		for (i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << '\n';
	} while (next_permutation(arr.begin(), arr.begin()+n));
}
