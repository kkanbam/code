/*
	20181029
	4014. 활주로 건설

	풀이:
	모든 예외 케이스(가령, 올라가는 케이스, 내려가는 케이스, 마지막에 1개만 남는 케이스)를 고려하도록 한다.
	조건 빼놓지 않도록 주의할 것.
*/
#include <iostream>

using namespace std;

int main()
{
	int n;

	int k, cnt;
	int i, j;

	int l;
	bool ok = true;

	int a[20][20];

	int tc, tc_cnt;
	cin >> tc;
	tc_cnt = 0;

	while (tc_cnt < tc) { 

		cin >> n >> l;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		int sp, ans = 0;

		//  Horizontal
		for (int i = 0; i < n; i++) {

			j = 0;
			ok = true;
			cnt = 0;

			while (j < n) {
				if (j == 0) sp = a[i][j];

				if (a[i][j] == sp) cnt++;

				if (a[i][j] != sp && (a[i][j] >= sp+2 || a[i][j] <= sp-2)) {
					ok = false;
					break;
				}
//cout << "a[" << i << "][" << j << "]=" << a[i][j] << ", sp=" << sp << "\n";	
				if (a[i][j] != sp && a[i][j] == sp-1) {
					//cout << "downcase:j=" << j << "\n";
					cnt = 0;
//						cout << "n=" << n << ",j="<<j << ",n-j=" << n-j << ", l=" << l << "\n";
					if (n-j < l) {
//						cout << "short:(" << i << "," << j << "), n-j = " << n-j << "\n"; 
						ok = false;
						break;
					}

					sp = a[i][j];
					k = 0;
	
					while (j < n && k < l) {
						if (a[i][j] != sp) {
					//		cout << "NOK:j=" << j << ", a[i][j]=" << a[i][j] << "\n";
							ok = false;
							break;		
						}
					//	cout << "G:j=" << j << ", a[i][j]=" << a[i][j] << "\n";
						j++;
						k++;
					}
					if (!ok || k != l) break;
					else if (ok) {j--;sp = a[i][j]; cnt=0;}
				}

				if (a[i][j] != sp && a[i][j] == sp+1) {
					//cout << "cnt=" << cnt << "\n";

					if (cnt < l) {
						ok = false;
						break;
					}
					else {
						sp = a[i][j];
						cnt = 1;
					}
				}

				j++;
			}

			if (ok) {
				ans++;
//				cout << "ANS(i)=" << i << "\n";
			}

		}

		// Verizon
		for (int j = 0; j < n; j++) {

			i = 0;
			ok = true;
			cnt = 0;

			while (i < n) {
				if (i == 0) {
					sp = a[i][j];
			//		cout << "init:sp=" << sp <<",i=" << i << ",j=" << j << "\n";
				}

				if (a[i][j] == sp) {
					cnt++;
				//	cout << "cnt=" << cnt << "\n";
				}

				if (a[i][j] != sp && (a[i][j] >= sp+2 || a[i][j] <= sp-2)) {
					ok = false;
					break;
				}
	
				if (a[i][j] != sp && a[i][j] == sp-1) {
					//cout << "here=(" << i << "," << j << ")\n";
					if (n-i < l) {
						ok = false;
						break;
					}

					sp = a[i][j];
					k = 0;
	
					while (i < n && k < l) {
						if (a[i][j] != sp) {
					//		cout << "i=" << i << ", a[i]=" << a[i] << "\n";
							ok = false;
							break;		
						}
					//	cout << "G:i=" << i << ", a[i]=" << a[i] << "\n";
						i++;
						k++;
					}
					if (!ok) break;
					else if (ok) {i--;sp = a[i][j]; cnt = 0;}
				}

				if (a[i][j] != sp && a[i][j] == sp+1) {
				//	cout << "sp=" << sp << ",a[" << i << "][" << j << "]=" << a[i][j] << ", cnt=" << cnt << ",l=" << l <<"\n";

					if (cnt < l) {
//						cout << "a[" << i << "][" << j << "]=FAIL, cnt=" << cnt << ",l=" << l << "\n";
						ok = false;
						break;
					}
					else {
						sp = a[i][j];
						cnt = 1;
					}
				}

				i++;
			}

			if (ok) {
				ans++;
//				cout << "ANS(j)=" << j << "\n";	
			}
		}
		

		cout << "#" << tc_cnt+1 << " " << ans << "\n";


		ans = 0;
		ok = true;
		tc_cnt++;

	};
}
