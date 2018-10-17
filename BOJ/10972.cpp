/*
	20181016
	10972. 다음 순열 #브루트포스 #틀림

	풀이:
	순열 구하기 법칙 이용
	입력이 3 2 6 1 5 4 인 경우 (참조: http://kwanghyuk.tistory.com/25)
	1. 순열의 오른쪽 끝에서부터, i-1 > i를 만족하지 않는 경우를 찾는다.
		예) 3 2 6 1 / 5 4
	2. i-1에 있는 숫자를 기준으로, 순열의 오른쪽 끝에서부터 i까지 탐색하여, i-1보다 큰 숫자가 나오면 i-1와 교환한다.
		예) 3 2 6 1 / 5 4 에서, 오른쪽 끝에서부터 탐색하여 처음으로 1보다 큰 수가 4이다. 1과 4를 교환한다.
		예) 3 2 6 4 / 5 1
	3. i부터 n-1까지 오름차순으로 정렬한다.
		예) 3 2 6 4 / 1 5
*/
#include <iostream>
#include <algorithm>

using namespace std;

void swap(int *a, int *b);

int main()
{
	int arr[10000];
	int min;
	int n;
	int idx, low_idx;

	cin >> n;

	int i = 0;

	for (i = 0; i < n; i++) {
		cin >> arr[i]; // 입력 받음
	}

	i -= 1;	// i = n-1 (순열의 마지막 요소) 대입

	while (arr[i-1] > arr[i] && i-1 >= 0) { // i-1번째 요소가 i번째 요소보다 큰 동안, 그리고 i-1이 0일 때까지
		i -= 1;
	}
	
	if (i == 0) cout << "-1" << '\n'; // i=0에 이를 때까지 오름차순이면, 맨 마지막 순열이므로 -1 출력
	else if (i == n-1) {				// i=n-1이면, 마지막 요소이므로, i-1번째 요소와 교환하는 것이 유일한 경우의 수
		swap(&arr[i-1], &arr[i]);
		for (i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
	}
	else {							// i=0이 아니고 i=n-1이 아니면, i가 중간에 멈춘 평범한 상태 
		idx = i-1; 					// i-1에 있는 요소가 교환의 대상이 되므로 저장해 놓음
		for (i = n-1; i > idx; i--) {	// 오른쪽부터 검색해야 하므로, i=n-1부터 i까지 검색함
			if (arr[i] > arr[idx]) break; // i번째 요소가 아까 idx에 저장한 요소보다 크다면, break
		}

		swap(arr[idx], arr[i]);	// idx에 있는 요소와 i번째 요소를 교환
		sort(arr+idx+1, arr+n);	// idx다음에 있는 요소부터 n번째 요소까지 오름차순으로 정렬
		
		// print
		for (i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
	}
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
