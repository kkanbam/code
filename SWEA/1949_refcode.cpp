/*
	20181025
	1929. 등산로 조성 #DFS #백트래킹 #틀림
	참고: http://henry121407.tistory.com/75
*/
#include <iostream>

using namespace std;

int max(int a, int b)
{
	int temp = (a > b)? a : b;
	return temp;
}

int a[8][8] = {0, };
int ans;
int n = 0;
int k = 0;
int h_p_a[5][2] = {-1, }; // high pic loc
int h_p = 0;
bool visited[8][8] = {false, };
int d[4][2] = { {-1, 0}, {0, +1}, {+1, 0}, {0, -1}};

bool isCut = false;

void dfs(int ci, int cj, int len, int f)
{
	int cur_v, nv;
	//cout << "=============================================\n";
	int ni, nj;
	int temp_n_v;

	ans = max(ans, len);
	//cout << "ANS:" << ans << "\n";
	visited[ci][cj] = true;

	for (int i = 0; i < 4; i++) {
		ni = ci + d[i][0];
		nj = cj + d[i][1];
	//	cout << "i=" << i << ", ni=" << ni << ", nj=" << nj << "\n";

		if (ni < 0 || nj < 0 || ni >= n || nj >= n || visited[ni][nj]) continue; // 조건에 맞지 않는것은 continue로 패스한다.

		if (a[ci][cj] > a[ni][nj]) // 내리막길인 경우
			dfs(ni, nj, len+1, f); // 길이를 1 증가시켜주고 정상 진행
		else if (!f & a[ci][cj] > a[ni][nj]-k) { // 깎지 않았고, k를 깎는 작업을 진행할 수 있는 경우
			// 백트래킹
			int t = a[ni][nj];
			a[ni][nj] = a[ci][cj]-1; // a의 값을, 현재거에서 1 깎는 걸로 바꿔준다.
			dfs(ni, nj, len+1, 1); // len+1은 위와 동일하게 길이 늘이기, 1은 깎았음을 표시함.
			a[ni][nj] = t; // 그러고 나면 원래 값을 복원해 준다.
		}
	}
	visited[ci][cj] = false; // 방문한 이후에, visit을 false로 돌려준다.
}

int main()
{
	int tc;
	cin >> tc;

	int tc_cnt = 1;
	int max = 0;

	while (tc_cnt <= tc) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (a[i][j] > h_p) h_p = a[i][j];
			}
		}
		int peak_idx = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == h_p) {
					h_p_a[peak_idx][0] = i;
					h_p_a[peak_idx][1] = j;
					peak_idx++;
				}
			}
		}
		for (int i = 0; i < peak_idx; i++) {
			dfs(h_p_a[i][0], h_p_a[i][1], 1, 0); // 초기 길이 1, 0 == 안 깎았음.
		}

		// print result
		cout << "#" << tc_cnt << " " << ans << "\n";

		// reset variables
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++)
				visited[i][j] = false;
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 2; j++) {
				h_p_a[i][j] = -1;
			}
		}
		ans = 0;
		h_p = 0;

		tc_cnt++;
	};
}
