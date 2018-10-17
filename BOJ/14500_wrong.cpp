/*
	20181016
	14500. 테트로미노 #브루트포스 #틀림
*/
#include <iostream>

using namespace std;

int arr[1000][1000];

/*adj[figN][0][0], adj[0][0][1]
adj[0][1][0], adj[0][1][1]
adj[0][2][0], adj[0][2][1]
adj[0][3][0], adj[0][3][1]
*/
int adj[19][3][2] = {
	{{0, 1}, {0, 2}, {0, 3}}, // fig 1
	{{1, 0}, {2, 0}, {3, 0}}, // fig 2
	{{0, 1}, {1, 1}, {1, 2}}, // fig 3
	{{0, 1}, {-1, 1}, {-1, 2}}, // fig 4
	{{1, 0}, {1, 1}, {2, 1}}, // fig 5
	{{-1, 0}, {-1, 1}, {-2, 1}}, // fig 6
	{{1, 0}, {1, 1}, {1, 2}}, // fig 7
	{{1, 0}, {2, 0}, {0, 1}}, // fig 8
	{{0, 1}, {0, 2}, {1, 2}}, // fig 9
	{{0, 1}, {-1, 1}, {-2, 1}}, // fig 10
	{{0, 1}, {0, 2}, {-1, 2}}, // fig 11
	{{0, 1}, {1, 1}, {1, 2}}, // fig 12
	{{-1, 0}, {-1, 1}, {-1, 2}}, // fig 13
	{{1, 0}, {2, 0}, {2, 1}}, // fig 14
	{{1, 0}, {1, 1}, {0, 1}}, // fig 15
	{{0, 1}, {-1, 1}, {0, 2}}, // fig 16
	{{0, 1}, {1, 1}, {0, 2}}, // fig 17
	{{1, 0}, {2, 0}, {1, 1}}, // fig 18
	{{1, 0}, {2, 0}, {1, -1}}}; // fig 19

int main()
{
	int n, m;
	int sum_max = -1;
	int sum_temp = -1;
	int i = 0, j = 0;

	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
/*
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/

/*
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 3; j++) {
			cout << adj[i][j][0] << " " << adj[i][j][1] << " ";
		}
		cout << '\n';
	}*/

	// fig 1
	for (i = 0; i < n; i++) {
		for (j = 0; j < m-3; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[0][0][0]][j+adj[0][0][1]] +
				arr[i+adj[0][1][0]][j+adj[0][1][1]] +
				arr[i+adj[0][2][0]][j+adj[0][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 2
	for (i = 0; i < n-3; i++) {
		for (j = 0; j < m; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[1][0][0]][j+adj[1][0][1]] +
				arr[i+adj[1][1][0]][j+adj[1][1][1]] +
				arr[i+adj[1][2][0]][j+adj[1][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 3
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < m-2; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[2][0][0]][j+adj[2][0][1]] +
				arr[i+adj[2][1][0]][j+adj[2][1][1]] +
				arr[i+adj[2][2][0]][j+adj[2][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 4
	for (i = 1; i < n; i++) {
		for (j = 0; j < m-2; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[3][0][0]][j+adj[3][0][1]] +
				arr[i+adj[3][1][0]][j+adj[3][1][1]] +
				arr[i+adj[3][2][0]][j+adj[3][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 5
	for (i = 0; i < n-2; i++) {
		for (j = 0; j < m-1; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[4][0][0]][j+adj[4][0][1]] +
				arr[i+adj[4][1][0]][j+adj[4][1][1]] +
				arr[i+adj[4][2][0]][j+adj[4][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 6
	for (i = 2; i < n; i++) {
		for (j = 0; j < m-1; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[5][0][0]][j+adj[5][0][1]] +
				arr[i+adj[5][1][0]][j+adj[5][1][1]] +
				arr[i+adj[5][2][0]][j+adj[5][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 7
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < m-2; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[6][0][0]][j+adj[6][0][1]] +
				arr[i+adj[6][1][0]][j+adj[6][1][1]] +
				arr[i+adj[6][2][0]][j+adj[6][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 8
	for (i = 0; i < n-2; i++) {
		for (j = 0; j < m-1; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[7][0][0]][j+adj[7][0][1]] +
				arr[i+adj[7][1][0]][j+adj[7][1][1]] +
				arr[i+adj[7][2][0]][j+adj[7][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 9
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < m-2; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[8][0][0]][j+adj[8][0][1]] +
				arr[i+adj[8][1][0]][j+adj[8][1][1]] +
				arr[i+adj[8][2][0]][j+adj[8][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 10
	for (i = 2; i < n; i++) {
		for (j = 0; j < m-1; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[9][0][0]][j+adj[9][0][1]] +
				arr[i+adj[9][1][0]][j+adj[9][1][1]] +
				arr[i+adj[9][2][0]][j+adj[9][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 11
	for (i = 1; i < n; i++) {
		for (j = 0; j < m-2; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[10][0][0]][j+adj[10][0][1]] +
				arr[i+adj[10][1][0]][j+adj[10][1][1]] +
				arr[i+adj[10][2][0]][j+adj[10][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 12
	for (i = 0; i < n-2; i++) {
		for (j = 0; j < m-1; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[11][0][0]][j+adj[11][0][1]] +
				arr[i+adj[11][1][0]][j+adj[11][1][1]] +
				arr[i+adj[11][2][0]][j+adj[11][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 13
	for (i = 1; i < n; i++) {
		for (j = 0; j < m-2; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[12][0][0]][j+adj[12][0][1]] +
				arr[i+adj[12][1][0]][j+adj[12][1][1]] +
				arr[i+adj[12][2][0]][j+adj[12][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 14
	for (i = 0; i < n-2; i++) {
		for (j = 0; j < m-1; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[13][0][0]][j+adj[13][0][1]] +
				arr[i+adj[13][1][0]][j+adj[13][1][1]] +
				arr[i+adj[13][2][0]][j+adj[13][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 15
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < m-1; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[14][0][0]][j+adj[14][0][1]] +
				arr[i+adj[14][1][0]][j+adj[14][1][1]] +
				arr[i+adj[14][2][0]][j+adj[14][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 16
	for (i = 1; i < n; i++) {
		for (j = 0; j < m-2; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[15][0][0]][j+adj[15][0][1]] +
				arr[i+adj[15][1][0]][j+adj[15][1][1]] +
				arr[i+adj[15][2][0]][j+adj[15][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 17
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < m-2; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[16][0][0]][j+adj[16][0][1]] +
				arr[i+adj[16][1][0]][j+adj[16][1][1]] +
				arr[i+adj[16][2][0]][j+adj[16][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 18
	for (i = 0; i < n-2; i++) {
		for (j = 0; j < m-1; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[17][0][0]][j+adj[17][0][1]] +
				arr[i+adj[17][1][0]][j+adj[17][1][1]] +
				arr[i+adj[17][2][0]][j+adj[17][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	// fig 19
	for (i = 0; i < n-2; i++) {
		for (j = 1; j < m; j++) {
			sum_temp = arr[i][j] +
				arr[i+adj[18][0][0]][j+adj[18][0][1]] +
				arr[i+adj[18][1][0]][j+adj[18][1][1]] +
				arr[i+adj[18][2][0]][j+adj[18][2][1]];
			if (sum_temp > sum_max) sum_max = sum_temp;
		}
	}

	cout << sum_max << '\n';
}
