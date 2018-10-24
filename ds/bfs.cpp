/* bfs sample code */
void bfs(int x)
{
	queue<int> q; // bfs 구현을 위한 q를 선언
	check[1] = true; // 첫 번째 정점 1을 방무했음을 선언한다.
	q.push(1); // 방문한 정점을 q에 넣는다.

	while (!q.empty()) {
		int a = q.front(); // q에 들어가 있는 요소를 참조한다.
		q.pop(); // pop해서 버림(?)
		cout << x << '\n'; // 사용함

		for (int i = 1; i <=n; i++) { // 1번째 정점부터 n번째 정점까지
			if (a[x][i] == 1 && check[i] == false) { // 간선이 있으면, 그리고 방문한 적 없으면
				check[i] = true; // 방문할 거니까 방문했다고 함
				q.push(i); // q에 push함
			}
		}
	};
}
