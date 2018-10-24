/*
	20181022-20181023
	1953. 탈주범 검거 #BFS

	풀이:
	각 방향의 파이프가 현재 칸의 파이프와 이어졌는지, 0이 아닌지를 체크하여 모두 q에 넣는다.
	q에서 pop하면서 동일한 루트를 탄다.

	주의:
	i, j 인덱스를 헷갈린 것. 특히, 파이프 좌표 넣어줄 때 조심할 것.
	**** 49/50의 마수: 마지막 케이스는 time=1일때 1을 리턴해야 함을 캐치하지 못했음.
	https://www.swexpertacademy.com/main/talk/solvingTalk/boardCommuView.do?searchCondition=COMMU_DETAIL-COMMU_TITLE-NICK_NAME_TAG&commuId=AWZ8eY66PFwDFAUQ&searchKeyword=%ED%83%88%EC%A3%BC%EB%B2%94&orderBy=DATE_DESC&pageSize=10&pageIndex=1
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define Y_IDX 0
#define X_IDX 1

#define I_IDX 0 // for forward op
#define J_IDX 1

int ndir[8][4][2] = {
    { {0, 0}, {0, 0}, {0, 0}, {0, 0} }, // 0, empty
    { {-1, 0}, {0, +1}, {+1, 0}, {0, -1} }, // 1
    { {-1, 0}, {+1, 0}, {0, 0}, {0, 0} }, // 2
    { {0, +1}, {0, -1}, {0, 0}, {0, 0} }, // 3 
    { {-1, 0}, {0, +1}, {0, 0}, {0, 0} }, // 4
    { {0, +1}, {+1, 0}, {0, 0}, {0, 0} }, // 5
    { {+1, 0}, {0, -1}, {0, 0}, {0, 0} }, // 6
    { {0, -1}, {-1, 0}, {0, 0}, {0, 0} } }; // 7
    
int map[55][55] = {-1, };
bool visited[55][55] = {false, };
int timeleft[55][55] = {-1, };
bool first;

int ans = 0;
int n, m;
int i_loc, j_loc;
int i, j;
int escape_time;
queue<pair<int, int> > q;

void bfs()
{
    while (!q.empty() && escape_time > 0) {
        int cur_i = q.front().first;
        int cur_j = q.front().second;
        q.pop();
        
        int pipe_num = map[cur_i][cur_j];
		if (pipe_num == 0) continue;
		if (visited[cur_i][cur_j] == true) continue;
		if (timeleft[cur_i][cur_j]-1 == 0) return;

		if (first) first = false;
		else {
			timeleft[cur_i][cur_j]--;
		//	cout << "timeleft=" << timeleft[cur_i][cur_j] << "\n";
		}
		ans++;
		//cout << "ans=" << ans << "\n";
	
		visited[cur_i][cur_j] = true;

        //cout << "p_num=" << pipe_num << '\n';

		for (int i = 0; i < 4; i++) {
			int nx = cur_j + ndir[pipe_num][i][X_IDX];
			int ny = cur_i + ndir[pipe_num][i][Y_IDX];

          //  cout << "i:" << i << '\n';
            //cout << "NEXT: (" << ny << ", " << nx << ")\n";
            //if (visited[ny][nx] == true) cout << "next visited" << '\n';
          	
/* DEBUG ENDS */ 
			if ((ny >= 0) && (ny < n) && (nx >= 0) && (nx < m) && map[ny][nx] != 0 && !visited[ny][nx]) {
				int next_pipe_num = map[ny][nx];
             //   cout << "n_p_n=" << next_pipe_num << '\n';

				int x_idx = 0, y_idx = 0;
				if (ndir[pipe_num][i][X_IDX] != 0) {
                    x_idx = -1 * ndir[pipe_num][i][X_IDX];
               //     cout << "x_idx=" << x_idx << "\n";
                }
               
				if (ndir[pipe_num][i][Y_IDX] != 0) {
                    y_idx = -1 * ndir[pipe_num][i][Y_IDX];
                 //   cout << "y_idx=" << y_idx << "\n";
                }
                
				int j;
				for (j = 0; j < 4; j++) {
                    //cout << "j=" << j << ", ndir[next_pipe_num][j][X_IDX]=" << ndir[next_pipe_num][j][X_IDX]  << ", ndir[next_pipe_num][j][Y_IDX]=" << ndir[next_pipe_num][j][Y_IDX] << "\n"; 
					//if (ndir[next_pipe_num][j][X_IDX] == x_idx) break;
					//if (ndir[next_pipe_num][j][Y_IDX] == y_idx) break;
					if (ndir[pipe_num][i][X_IDX] != 0) { // check x_idx
						if (ndir[next_pipe_num][j][X_IDX] == x_idx) break;
					}
					if (ndir[pipe_num][i][Y_IDX] != 0) { // check y_idx
						if (ndir[next_pipe_num][j][Y_IDX] == y_idx) break;
					}
				}
//cout << "j=" << j << "\n";
				if (j != 4) {
					// push
					q.push( {ny, nx} );
                   // cout << "push(" << ny << ", " << nx << ")\n";
					timeleft[ny][nx] = timeleft[cur_i][cur_j];
				}
			}
		}
	};

/*
        if (pipe_num != 0 && pipe_num != 1) {
            for (int i = 0; i < 4; i++) {
                cout << "@B" << i << endl;
                int nx = cur_j + ndir[pipe_num][i][X_IDX];
                int ny = cur_i + ndir[pipe_num][i][Y_IDX];

                int next_pipe_num = map[ny][nx];
                          cout << "nx:" << nx << ",ny:" << ny << ", n_p_n:" << next_pipe_num << '\n';      
                if ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m) && map[ny][nx] != 0 && !visited[ny][nx]) {
                    //if (isConnected(ndir[pipe_num][i], ndir[next_pipe_num][i])) {
                   	if (isConnected(pipe_num, next_pipe_num))
                        q.push({ny, nx});
                        timeleft[ny][nx] = timeleft[cur_i][cur_j] - 1;
                        ans++;
                    }
                }
            }
        }*/
    return;
}

int main()
{
    int tc;
    int i, j;
    
    cin >> tc;
    int tc_count = 0;
    
    while (tc_count < tc) {
        cin >> n >> m >> i_loc >> j_loc >> escape_time;
      //  cout << "input i_loc: " << i_loc << ", j_loc:" << j_loc << ", escape_time:" << escape_time << '\n';

        first = true;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> map[i][j];   
            }
        }
        
        ans = 0;
        q.push({i_loc, j_loc});
        timeleft[i_loc][j_loc] = escape_time;
        bfs();
     
        tc_count++;
		if (escape_time == 1) ans = 1;
        cout << "#" << tc_count << " " << ans << '\n';
        while (!q.empty()) q.pop();
        for (i = 0; i < 55; i++) {
        	for (j = 0; j < 55; j++) {
            	visited[i][j] = false;   
				map[i][j] = -1;
				timeleft[i][j] = -1;
            }
        }
        first = true;
    }
    return 0; // program ends
}
