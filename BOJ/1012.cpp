/*
	20181030
	1014. 유기농 배추 #DFS

	풀이:
	각 그래프를 쪼개서, 부분 그래프에서 각각 dfs를 돌려줘서 인접한 1인 요소는 모두 방문했음을 표기한다.
	다음 부분 그래프는 1이면서(요소가 있으면서) 방문하지 않은 점을 찾는다.

	주의:
	dfs내부에서도 0이 아닌 요소를 찾아서 dfs를 돌려줘야 한다는 사실을 까먹지 말 것 
*/
#include <iostream>

using namespace std;

int map[50][50] = {0, };
int m, n, k;
bool v[50][50] = {false, };

class pli {
	int i;
	int j;
};

int ans = 0;

int dp[4][2] = { {-1, 0}, {0, +1}, {+1, 0}, {0, -1}};

void dfs(int i, int j)
{
	v[i][j] = true;
	//cout << "v[" << i << "][" << j << "] visit\n";
	
	for (int idx = 0; idx < 4; idx++) {
		int ni = i + dp[idx][0];
		int nj = j + dp[idx][1];

		if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
		if (v[ni][nj]) continue;
		if (map[ni][nj] != 0) dfs(ni, nj);
	}
	
}

int main()
{
	int tc, tcnt = 0;
	int x, y = 0;

	cin >> tc;

	while (tcnt < tc) {
		cin >> m >> n >> k;
		// n = i
		// m = j
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				map[i][j] = 0;
				v[i][j] = false;
			}
		} // 배추밭 초기화
		ans = 0; // ans init

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[y][x] = 1; // 배추 심기
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j]) continue;
			//	else {
			//		if (map[i][j] != 0) { 
			//			cout << "(" << i << "," << j << ")\n";
			//		}
			//	}
				else if (v[i][j] == false) {
					if (map[i][j] != 0) {
						dfs(i, j);
						ans++;
			//			cout << "ans++ at (" << i << "," << j << ")\n";
					}
				}				
			}
		}	

		cout << ans << "\n";
		tcnt++;
	}
}
