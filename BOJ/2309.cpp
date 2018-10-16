/*
	20181015
	2309. 일곱 난쟁이 #브루트포스 #틀림

	풀이:
	1. 아홉 난쟁이의 키를 모두 받아 배열에 저장한다.
	2. 오름차순으로 정렬한다.
	3. 두 난쟁이를 2중 for문을 사용하여 선택한다.
	4. sum(아홉 난쟁이 키) - sum(선택한 두 난쟁이 키) == 100이 되는 답을 찾는다.

	주의:
	두 난쟁이를 고르는 for문을 잘 구현해야 함.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int arr[9];
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];	// 입력과 동시에 sum을 받아둔다.
	}

	sort(arr, arr+9); // 오름차순으로 미리 정렬한다.

	for (int i = 0; i < 9-1; i++) {	// 1~8번째 난쟁이
		for (int j = i; j < 9; j++) { // 2~9번째 난쟁이
			if (sum - arr[i] - arr[j] == 100) {	// 전체 sum에서 i, j번째 난쟁이의 키를 뺀 값이 100이 되는 경우
				for (int k = 0; k < 9; k++) {	// 출력을 위한 for문
					if (k != i && k != j)	// 빠진 난쟁이가 아니면
						cout << arr[k] << '\n';
				}
				return 0;
			}		
		}
	}
}
