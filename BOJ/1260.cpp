/*
	20181024
	1260. DFS와 BFS #DFS #BFS

	주의:
	양쪽 간선도 처리해줄 것.
	왜 시작점을 문제에서 주어진 v가 아니라 1로 고정해 놓은거니?..
*/
#include <iostream>
#include <queue>

using namespace std;

#define V_MAX 1001
int graph[V_MAX][V_MAX] = {0, };
bool check[V_MAX] = {false, };

void dfs(int v)
{
	check[v] = true;
	cout << v << " ";

	for (int i = 1; i <= 1000; i++) {
		if (graph[v][i] == 1 && check[i] == false) {
			dfs(i);
		}
	}
}

void bfs(int v)
{
	queue<int> q;
	check[v] = true;
	q.push(v);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << " ";

		for (int i = 1; i <= 1000; i++) {
			if (graph[v][i] == 1 && check[i] == false) {
				check[i] = true;
				q.push(i);
			}
		}
	};
}


int main()
{
	int n, m, v;
	int s_v, d_v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> s_v >> d_v;
		if (graph[s_v][d_v] == 1) continue;
		graph[s_v][d_v] = graph[d_v][s_v] = 1;
	}

	dfs(v);

	for (int i = 1; i <= 1000; i++) {
		check[i] = false;
	}
	cout << "\n";

	bfs(v);

	for (int i = 1; i <= 1000; i++) {
		check[i] = false;
		for (int j = 1; j <= 1000; j++) 
			graph[i][j] = 0;
	}
			
}
