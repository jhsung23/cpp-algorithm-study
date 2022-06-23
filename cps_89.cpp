#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct Loc {
	int x;
	int y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int> > tomato(m, vector<int>(n, 0));
	vector<vector<int> > ch(m, vector<int>(n, 0));
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	queue<Loc> Q;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tomato[i][j];
			ch[i][j] = tomato[i][j];
			if (tomato[i][j] == 1) {
				Q.push(Loc(i, j));
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			/*if (tomato[i][j] == 1) {
				Q.push(Loc(i, j));
			}*/
			while (!Q.empty()) {
				Loc tmp = Q.front();
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int xx = tmp.x + dx[i];
					int yy = tmp.y + dy[i];

					if (xx>=0 && xx<m && yy>=0 && yy<n) {
						if (tomato[xx][yy] == 0) {
							Q.push(Loc(xx, yy));
							tomato[xx][yy] = 1;
							ch[xx][yy] = ch[tmp.x][tmp.y] + 1;
						}
					}
					/*for (int i = 0; i < m; i++) {
						for (int j = 0; j < n; j++) {
							cout << ch[i][j] << " ";
						}
						cout << endl;
					}
					cout << "----------------------" << endl;*/
				}

			}
		}
	}

	int res = -1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (ch[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (res < ch[i][j]) res = ch[i][j];
		}
	}
	cout << res-1;
	return 0;
}
