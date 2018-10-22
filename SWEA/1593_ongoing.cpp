/*
    20181022
    1953.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define Y_IDX 0 // for forward op
#define X_IDX 1

int ndir[8][4][2] = {
    { {0, 0}, {0, 0}, {0, 0}, {0, 0} }, // 0, empty
    { {-1, 0}, {0, +1}, {+1, 0}, {0, -1} }, // 1
    { {-1, 0}, {+1, 0}, {0, 0}, {0, 0} }, // 2
    { {0, +1}, {0, -1}, {0, 0}, {0, 0} }, // 3 
    { {-1, 0}, {0, +1}, {0, 0}, {0, 0} }, // 4
    { {0, +1}, {+1, 0}, {0, 0}, {0, 0} }, // 5
    { {+1, 0}, {0, -1}, {0, 0}, {0, 0} }, // 6
    { {0, -1}, {-1, 0}, {0, 0}, {0, 0} } }; // 7
    
int map[50][50] = {-1, };
bool visited[50][50] = {false, };
int timeleft[50][50] = {0, };

int ans = 0;
int n, m;
int i_loc, j_loc;
int escape_time;
queue<pair<int, int> > q;
/*
bool isConnected(int src[2], int dst[2])
{    
    if (src[X_IDX] != 0 && src[Y_IDX] == 0) {// X_IDX 
        if ((dst[X_IDX] *= -1) == src[X_IDX]) {cout << "x_idx connect" << endl; return true;}
    	else cout << "x_idx dismatch" << endl;}
    
    if (src[X_IDX] == 0 && src[Y_IDX] != 0){ // Y_IDX
        if ((dst[Y_IDX] *= -1) == src[Y_IDX]) {cout << "y_idx connect" << endl; return true;}
    	else cout << "y_idx dismatch" << endl;}
    return false;
}*/

void bfs()
{
    while (!q.empty() && escape_time > 0) {
        int cur_i = q.front().first;
        int cur_j = q.front().second;
        cout << "cur_i:" << cur_i << ", cur_j:" << cur_j << endl;
        q.pop();
        
        int pipe_num = map[cur_i][cur_j];

        if (pipe_num == 0) continue;
        if (timeleft[cur_i][cur_j] == 0) return;
        visited[cur_i][cur_j] = true;
		ans++;
        cout << "ans++\n";
       
        cout << "p_num:" << pipe_num << '\n';

		for (int i = 0; i < 4; i++) {
			int nx = cur_j + ndir[pipe_num][i][X_IDX];
			int ny = cur_i + ndir[pipe_num][i][Y_IDX];
            cout << "i:" << i << '\n';

			if ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m) && map[ny][nx] != 0 && !visited[ny][nx]) {
				int next_pipe_num = map[ny][nx];

				int x_idx = 0, y_idx = 0;
				if (ndir[pipe_num][i][X_IDX] != 0) x_idx = -1 * ndir[pipe_num][i][X_IDX];
				if (ndir[pipe_num][i][Y_IDX] != 0) y_idx = -1 * ndir[pipe_num][i][Y_IDX];
				
				int j;
				for (j = 0; j < 4; j++) {
					if (ndir[next_pipe_num][j][X_IDX] == x_idx) break;
					if (ndir[next_pipe_num][j][Y_IDX] == y_idx) break;
				}
				if (j != 4) {
					// push
					q.push( {ny, nx} );
					timeleft[ny][nx] = timeleft[cur_i][cur_j] - 1;
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
        cout << "input i_loc: " << i_loc << ", j_loc:" << j_loc << '\n';

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
        cout << "##############" << tc_count << " " << ans << '\n';
        while (!q.empty()) q.pop();
        for (i = 0; i < 50; i++) {
        	for (j = 0; j < 50; j++) {
            	visited[i][j] = false;   
            }
        }
    }
    return 0; // program ends
}
