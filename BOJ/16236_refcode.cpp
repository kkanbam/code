/*
	20181022
	16236. 아기 상어 #기출 #BFS #틀림
    
	참고 코드: Crocus 님 (https://www.crocus.co.kr/1390)
	아래 코드는 상기 사이트 운영자에게 모든 저작권이 귀속됩니다.
	문제 시 즉시 삭제하겠으니 suy.suy.lee@gmail.com으로 연락 주세요.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 987654321 // 종료 조건

using namespace std;

typedef pair<int, int> loc; // x, y 좌표를 나타내는 pair를 정의함

int arr[22][22]; // 전체 칸을 나타내는 것으로 추정
int dy[4] = { -1,  0, 0, 1 }; // 동서남북 방위를 나타냄
int dx[4] = {  0, -1, 1, 0 };
bool visit[22][22]; // 해당 칸을 방문했는지 여부, 그런데 왜 22지?

int n; // 네모판의 크기
int sy, sx; // 현재 상어의 위치
int sSize = 2;	// 상어의 초기 사이즈
int eat;	// 상어가 몇 마리나 먹었는지 (사이즈 안에서 카운트)
int ans;	// 몇 초 (몇 거리) 가 걸렸는지 누산하는 카운터

// 리턴값이 int, int로 이루어진 구조체 2개임.
// 앞에건 x, y좌표, 뒤에건 dist, size정보를 리턴함.

pair<loc, loc> bfs() { 
	memset(visit, 0, sizeof(visit)); // visit 0으로 초기화. 방문하지 않았음.

	queue<pair<loc, int> > q; // 위치(loc)와 거리(int)를 나타내는 pair로 queue를 만들어줌. 먹이 q가 됨.
	q.push( { {sy, sx}, 0}  ); // q에다 상어의 현재 위치, 아직 이동할 칸을 정하지 않았으므로 dist를 0으로 넣어줌.

	vector<pair<int, loc> > shark;	// 결과가 저장될 배열임

	while (!q.empty()) { // queue가 빌 때까지?
		int y = q.front().first.first; // loc 구조체의 첫번째 요소이므로 sy
		int x = q.front().first.second; // loc 구조체의 두번째 요소이므로 sx
		int dist = q.front().second; // 뭔진 잘 모르겠지만 shark까지의 거리
		q.pop();	// queue를 참조한 후 pop한다. (참조부터 위에 먼저 함)

		if (arr[y][x] != 0 && arr[y][x] < sSize)  // sy, sx가 0이 아니고(물고기가 있고), 해당 칸의 사이즈가 sSize (샤크 사이즈) 보다 작은 경우
			shark.push_back({dist, { y,x } }); // shark에 거리와 좌표를 넣는다?

		if (visit[y][x])	// 방문한 자리인 경우
			continue;

		visit[y][x] = true;	// 상어가 방문한 자리는 방문했음으로 표시함.

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y; // 다음 좌표를 계산한다. 4방향이므로 for문을 돌려 계산한다.
			int nx = dx[i] + x;

			if ((0 <= ny && ny < n) && (0 <= nx && nx < n) && arr[ny][nx] <= sSize) 
			// 1. ny, nx가 네모 판 안에 들어오는 숫자여야 한다.
			// 2. 이동할 칸이 상어 사이즈보다 작아야 한다 (즉, 상어 사이즈보다 작거나 0이어야 한다)
				q.push({ {ny, nx}, dist + 1 });	// 다음 칸으로 이동하니까, dist + 1을 넣고, 또 loc을 푸시한다.
		}
	}

	if (shark.empty())
		return { {INF, INF}, {INF, INF} };	// 만약 shark 배열이 empty라면 종료 조건을 리턴한다. 왜 두개씩이지? 언제 푸시됐다고...

	sort(shark.begin(), shark.end());	// 있다고 치고, 처음부터 끝까지 sort한다.

	int dist = shark[0].first;
	int y = shark[0].second.first;
	int x = shark[0].second.second;
	int size = arr[y][x];	// shark에 푸시된 가장 가까운 (dist 정렬이니까) 먹잇감의 사이즈
	return { {y, x}, {dist, size} };	// 리턴값은 가장 가까운 먹잇감의 좌표와 거리, 사이즈가 된다.
}


int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];	// 배열의 x, y에 있는 값을 입력받는다.
			if (arr[i][j] == 9) // 만약 입력받은 값이 9라면 '상어'다---
				sy = i, sx = j, arr[i][j] = 0;	// 현재의 shark 좌표를 sy, sx에 설정한다. arr에 0값을 넣는다. 이건 왜?
		}
	}

	while (1) {
		pair<loc, loc> tmp = bfs();	// 리턴값이 뭔가?
		if (tmp.second.first == INF) // dist가 infinity면 break한다. 더이상 탐색할 수 있는 지점이 없다.
			break;

		int y = tmp.first.first;	// loc.y
		int x = tmp.first.second;	// loc.x
		int dist = tmp.second.first;	// dist
		int size = tmp.second.second;	// target size

		ans += dist; // 타겟 먹이까지의 dist를 ans에 가산함. 그런데, dist는 어디서 계산하지?

		sy = y;
		sx = x;	// 먹었으니까 shark의 위치를 방금 먹은 물고기 위치로 치환함.
		eat++;	// 먹은 횟수를 더한다. 이건 나중에 사용할 것임.
		arr[y][x] = 0;	// 물고기를 먹었으니 그 위치엔 이제 아무것도 없다. 0으로 바꿔줌.
		if (eat == sSize)	// 물고기를 먹었는데 그게 sSize만큼이 되면, 상어의 크기가 커진다.
			sSize++, eat = 0;	// 먹은 횟수를 초기화시켜줘야함. sSize만큼 eat이 증가되어야 sSize가 증가되기 떄문임.
	}

	cout << ans << '\n';
	return 0;
}
