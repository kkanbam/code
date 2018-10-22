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
    
int map[50][50] = {0, };
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
        cout << "1\n";
        int cur_i = q.front().first;
        int cur_j = q.front().second;
        cout << "cur_i:" << cur_i << ", cur_j:" << cur_j << endl;
        q.pop();
        
        int pipe_num = map[cur_i][cur_j];

        if (pipe_num == 0) continue;
        if (timeleft[cur_i][cur_j] == 0) cout << "return!!\n";
        visited[cur_i][cur_j] = true;
        
        cout << "p_num:" << pipe_num << '\n';
        if (pipe_num == 1) {// 4 cases
            for (int i = 0; i < 4; i++) {
                cout << "@" << i << endl;
                int nx = cur_j + ndir[pipe_num][i][X_IDX];
                int ny = cur_i + ndir[pipe_num][i][Y_IDX];
                int next_pipe_num = map[ny][nx];
                
                if ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m) && map[ny][nx] != 0 && !visited[ny][nx]) {
                    //find
                    if (isConnected(pipe_num, next_pipe_num)) {
                        cout << "connected to: " << ny << ", " << nx << '\n';
                        q.push({ny, nx});
                        timeleft[ny][nx] = timeleft[cur_i][cur_j] - 1;
                        ans++;
                    }
                }
            }
        }
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
        }

    };

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
        cout << "#" << tc_count << " " << ans << '\n';
    }
    return 0; // program ends
}
