/*
	20181017
	10971. 외판원 순회 2 #브루트포스 #순열쓰는건맞음 #틀림

	주의
	#순열 : 모든 요소가 각 한 번씩 나와야 하고 모든 순서를 만들어봐야 할 때 유용하다.
	+ 순열을 이용한다는 컨셉 자체는 잘 떠올렸음.	
	- 조건 하나를 빼먹었음: i->j가 0일 때 갈 수 없는 길이고 이부분을 빼줘야 함.
	- 인덱스를 제대로 넣어주지 않았음. 인덱스 제대로 체크할 것.
	- sum을 충분히 크게 줘야함.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, i, j, k;
	int w[10][10];	// max
	//vector<int, int> w(10)(10);
	//bool check[10];
	int temp_sum = 0, min_sum = 100000000;	// 초기값 sum은 충분히 큰 수로 만들어 줌
	bool ok = true;
	vector<int> arr(10); // 순열을 만들기 위한 배열을 만들어 줌

	cin >> n;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	for (i = 0; i < n; i++) {
		arr[i] = i;
	}

	do { // make permutation
		temp_sum = 0;
		ok = true;
/* legacy
		for (i = 0; i < n; i++) {
			j = i%n - 1;
			k = (i+1)%n - 1;
			cout << i << " " << j << " " << k << endl;
			if (w[arr[j]][arr[k]] == 0) ok == false;
			temp_sum += w[arr[j]][arr[k]];
		}
		if (temp_sum < min_sum && ok) min_sum = temp_sum; */

		for (i = 0; i < n-1; i++) {
	//		cout << "i=" << i << ", start=" << arr[i]-1 << ", end=" << arr[i+1]-1 << endl;
			if (w[arr[i]][arr[i+1]] == 0) {	// 불가능한 길이므로
				ok = false;	// path 표지자를 false로 만들어줌
				//cout << "false!" << '\n';
			} else temp_sum += w[arr[i]][arr[i+1]]; // 가능한 길인 경우 sum에 가산
		}
		if (ok && w[arr[i]][arr[0]] != 0) { // 가능한 길이었을 경우, 그리고 초기점으로 돌아갈 수 있는 경우
			temp_sum += w[arr[i]][arr[0]]; // 초기점으로 돌아가는 길도 더해줌
	//		cout << "i=" << i << ", start=" << arr[i]-1 << ", end=" << arr[0]-1 << endl;
			if (temp_sum < min_sum) min_sum = temp_sum; // 가장 짧은 길이었을 경우 min_sum 갱신
		}
	} while (next_permutation(arr.begin(), arr.begin()+n));

	cout << min_sum << '\n';
}
