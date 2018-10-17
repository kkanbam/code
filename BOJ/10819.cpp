/*
	20181017
	10819. 차이를 최대로 #브루트포스 #틀림

	풀이:

	주의:
	각 자리에 위치할 수 있는 값의 조합을 순열로 파악해야 한다는 아이디어를 떠올리지 못했음.
	next_permutation은 algorithm 헤더 파일에 선언되어 있음
	구현 상의 주의점: 모든 순열을 다 돌아야 하므로, 맨 처음 순열로 만들어야 함.
	 - sort(arr.begin(), arr.begin()+n) 을 이용해서 맨 처음 순열로 만들어줘야 정확한 답이 나옴.
*/
#include <iostream>
#include <vector>
#include <algorithm>
//#include <math>

using namespace std;

int main()
{
	int n;
	int i, j;
	int max = -1, temp = 0;
	vector<int> arr(8); // 3 <= n <= 8

	cin >> n;

	for (i = 0; i < n; i++) 
		cin >> arr[i]; // 입력을 받음

	sort(arr.begin(), arr.begin()+n); // sort를 통해 오름차순 (첫 번째 순열) 으로 만들어줌 *매우 중요함

	do {
		temp = 0;
		for (i = 0; i < n-1; i++) { // i, i+1을 추출해야 하므로
			temp += abs(arr[i] - arr[i+1]);	// 문제의 조건
		}
		if (temp > max) max = temp; // 이전 저장된 값보다 새로 계산한 값 (temp) 이 더 크면 max에 저장한다.
//		cout << '\n';
	} while (next_permutation(arr.begin(), arr.begin()+n)); // n개까지이므로 최대값인 8을 더하지 않도록 주의한다.

	cout << max << '\n';
}
