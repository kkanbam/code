/*
	20181025
	1949. 등산로 조성 #DFS #백트래킹

	참조코드: http://henry121407.tistory.com/75
*/
#include <iostream>

using namespace std;

int a[8][8];
int n, k;
int h[5][2]; // high peak index
bool visited[8][8] = {false, };
int d[4][2] = { {-1, 0}, {0, +1}, {+1, 0}, {0, -1} };
int ans;

int max(int a, int b)
{
	int t = a > b? a : b;
	return t;
}

void dfs(int x, int y, int len/*자동 증가*/, bool cut)
{
	ans = max(ans, len);
	//cout << "ans=" << ans << "\n";
	visited[x][y] = true;

	int nx, ny;

	for (int i = 0; i < 4; i++) {
		nx = x + d[i][0];
		ny = y + d[i][1];

		//cout << "(" << nx << ", " << ny << ")\n";

		if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;

		if (a[x][y] > a[nx][ny]) { // 평범한 케이스인 경우
			dfs(nx, ny, len+1, cut);
		}
		else if (!cut && a[x][y] > a[nx][ny]-k) { // 만약 작지 않은 경우, 백트래킹 중요
			int t = a[nx][ny]; // 현재 next값 저장
			a[nx][ny] = a[x][y]-1; // next값을 임의로 현재 있는 정점보다 1 작게 수정
			dfs(nx, ny, len+1, true); // 그 상태로 검색
			a[nx][ny] = t; // restore
		}
	}
	visited[x][y] = false;
}

int main()
{
	int tc, tc_idx;
	int high_peak = 0;
	int high_peak_num = 0;

	cin >> tc;

	for (tc_idx = 1; tc_idx <= tc; tc_idx++) {
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (high_peak < a[i][j]) high_peak = a[i][j];
			}
		} 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == high_peak) {
					h[high_peak_num][0] = i;
					h[high_peak_num][1] = j;
					//cout << "h_p[" << high_peak_num << "]=" << i << ", " << j << "\n";
					high_peak_num++;
				}
			}
		}
		for (int i = 0; i < high_peak_num; i++) {
			//cout << "dfs" << i << "\n";
			dfs(h[i][0], h[i][1], 1, false);
		}
		
		cout << "#" << tc_idx << " " << ans << "\n";
		
		ans = 0;
	}
}
