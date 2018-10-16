/*
	20181016
	1476. 날짜 계산
*/
#include <iostream>

using namespace std;

int main()
{
	int e, s, m;
	int i;
	int n = 1;

	cin >> e >> s >> m;

	if ((e == 1) && (s == 1) && (m == 1)) cout << "1";
	else {
		i = 1;

		while (1) {
			n = (15 * i) + e;
			if (((n % 28 == s) && (n % 19 == m)) ||
				((n % 28 == 0) && (n % 19 == 0))) break;
			else i++;
		}

		cout << n << endl;
	}
}
