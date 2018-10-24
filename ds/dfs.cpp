/* dfs - vortex oriented sample code */
void dfs(int x)
{
	check[x] = true; // 방문하였음을 표지함
	cout << x << '\n'; // 방문한 정점을 프린트함

	for (int i = 0; i < a[x].size(); i++) { // a[x]는 정점 a[x]에 연결된 정점들의 리스트를 가지고 있음.
		int y = a[x][i]; // i 번째 정점을 가져옴
		if (check[y] == false) {// 방문한 적이 없으면
			dfs(y);
		}
	}
}

/* dfs - edge oriented sample code */
void dfs(int x)
{
	check[x] = true;
	cout << x << '\n';

	for (int i = 1; i <= n; i++) { // 정점 1~n까지 탐색한다
		if (a[x][i] == 1 && check[i] == false) { // a[x][i] = x에서 i 정점에 이르는 간선이 있는지를 나타냄
			dfs(i);
		}
	}
}
