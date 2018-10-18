/*
	20181018
	6603. 로또 #브루트포스 #순열
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; // input, numofdigits
//	vector<int> input_arr(50);
	int input_arr[49];
	vector<int> arr(6);	// 49=max, for storing permutation
	int i, j, k, l, idx;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> input_arr[i];
	}
/*
	cin >> input_arr[0];
	i = 0;
	while (i < input_arr[0]) {
		i++;
		cin >> input_arr[i];
		cout << input_arr[i] << " ";
	}*/
	for (i = 0; i < n-2; i++) {
		for (j = i+1; j < n-1; j++) {
			for (k = j+1; k < n; k++) {
//				cout << i << " " << j << " " << k << '\n';
				idx = 0;
				l = 0;
				while (idx < 6) {
					if (l != i && l != j && l != k) {
						arr[idx] = input_arr[l];
						cout << arr[idx] << " ";
					}
					idx++;
					l++;
				}
				cout << '\n';
			}
		}
	}		

}
