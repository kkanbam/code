/*
	20181019
	6603. 로또 #브루트포스 #순열 #틀림

	풀이:
	1을 6개, 0을 k-6개 넣고 순열을 만들면 모든 조합을 만들 수 있다.

	주의:
	선택한다, 선택하지 않는다를 표현하는 것으로 0(선택안함) 1(선택함)을 사용함.
	next_permutation은 오름차순으로 동작한다 -> 순열을 맨 처음으로 만들어줘야한다 -> 선택하지 않는 요소인 0부터 넣어줘야 한다. (1부터 넣어줬음, 그래서 한가지 순열만 만들어진 것이 패인)
	index 연산을 제대로 못하는 것 같음.
	++final_ans.clear()를 제대로 해주지 않으면 다음 테스트케이스에서도 fail이 남.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int input_arr[50];	// for input
	int k;	// max value
	int i, j, num_ans;
	vector<int> ans(6); // each answer
	vector<vector<int> > final_ans; // sorted answer

	while (true) {
		cin >> k;

		if (k == 0) break;

		vector<int> select_arr(k);

		for (i = 0; i < k; i++) {
			cin >> input_arr[i];
			//cout << input_arr[i] << " ";
		}
		//cout << '\n';

		for (i = 0; i < k-6; i++) {
			select_arr[i] = 0;
		//	cout << select_arr[i] << " ";
		}
		//cout << '\n';
		//cout << "target:" << k;
		while (i < k) {
			select_arr[i] = 1;
			i++;
		}

		num_ans = 0;

		do {
			for (i = 0; i < k; i++) {
		//		cout << select_arr[i] << ' ';
			}
		//	cout << '\n';
			// permutation
			i = 0;
			j = 0;
			for (i = 0; i < k; i++) {
				if (select_arr[i] == 1) {
					ans[j++] = input_arr[i];
				}
			}
			for (i = 0; i < 6; i++) {
		//		cout << ans[i] << ' ';
			}
	//		cout << '\n';

			final_ans.push_back(ans);			
			num_ans++;
		} while (next_permutation(select_arr.begin(), select_arr.end()));
		
		sort(final_ans.begin(), final_ans.begin()+num_ans);

		for (i = 0; i < num_ans; i++) {
			for (j = 0; j < 6; j++) {
				cout << final_ans[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
		final_ans.clear();
	};
}
