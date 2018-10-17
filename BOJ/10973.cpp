/*
	20181017
	10973. 이전 순열 #브루트포스

	풀이: 다음 순열 구하는 알고리즘을 변형해서 사용.
	1. 맨 오른쪽부터 순열을 탐색한다. 1 2 3 4 5는 i > i-1이 항상 성립함.
		- i = 0인 경우 모두 오름차순이므로 이전 순열이 없으므로 -1을 출력
		- i = n-1인 경우 모두 내림차순이므로 i와 i-1 요소를 교환
	2. i가 0이 아니고 n-1이 아닌 경우,
		- i-1을 idx에 저장한다 (해당 위치를 저장하기 위함임)
		- 오른쪽에서부터 idx보다 큰 인덱스까지 탐색하여 idx 요소보다 작은 수를 찾는다.
		- 해당 수와 idx 요소를 교환한다.
		- idx+1부터 n-1까지 내림차순 정렬한다.	

	주의: i 인덱스 초기화를 잊어서 틀림으로 나왔음. 인덱스 초기화 및 범위에 주의할 것.
	
*/
#include <iostream>
#include <algorithm>

using namespace std;

void swap(int *a, int *b);
bool desc(int a, int b);

int main()
{
	int n, arr[10000], i, idx, low_min;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	i = n-1;

	while (arr[i] > arr[i-1] && (i-1 >= 0)) {
		i -= 1;
	}

	if (i == 0) {
		cout << "-1";
	}
	else if (i == n-1) {
		swap(arr[i], arr[i-1]);

		for (i = 0; i < n; i++)
			cout << arr[i] << " ";
	}
	else {
		idx = i-1;

		for (i = n-1; i > idx; i--) {
			if (arr[i] < arr[idx]) {
				break;
			}
		}

		swap(arr[i], arr[idx]);
		sort(arr+idx+1, arr+n, desc);

		for (i = 0; i < n; i++)
			cout << arr[i] << " ";
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

bool desc(int a, int b)
{
	return a > b;
}
