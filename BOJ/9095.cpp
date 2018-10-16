/*
	20181016
	9095. 1, 2, 3 더하기

	풀이:
	n중 for문을 사용하여 답이 나오는 모든 케이스를 출력
*/
#include <iostream>

using namespace std;

int main()
{
	int n, tc;
	int ans;
	int l1, l2, l3, l4, l5, l6, l7, l8, l9, l10;

	cin >> tc;

	while (tc > 0) {
		ans = 0;
		cin >> n;

		for (l1 = 1; l1 <= 3; l1++) {
			if (l1 == n) ans++;
			for (l2 = 1; l2 <= 3; l2++) {
				if (l1 + l2 == n) ans++;
				for (l3 = 1; l3 <= 3; l3++) {
					if (l1 + l2 + l3 == n) ans++;
					for (l4 = 1; l4 <= 3; l4++) {
						if (l1 + l2 + l3 + l4 == n) ans++;
						for (l5 = 1; l5 <= 3; l5++) {
							if (l1 + l2 + l3 + l4 + l5 == n) ans++;
							for (l6 = 1; l6 <= 3; l6++) {
								if (l1 + l2 + l3 + l4 + l5 + l6 == n) ans++;
								for (l7 = 1; l7 <= 3; l7++) {
									if (l1 + l2 + l3 + l4 + l5 + l6 + l7 == n) ans++;
									for (l8 = 1; l8 <= 3; l8++) {
										if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 == n) ans++;
										for (l9 = 1; l9 <= 3; l9++) {
											if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 == n) ans++;
											for (l10 = 1; l10 <= 3; l10++) {
												if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 == n) ans++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

		cout << ans << endl;
		--tc;
	}

}
