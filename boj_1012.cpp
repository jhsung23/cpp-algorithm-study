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

	int t;
	cin >> t;

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	vector<int> res;

	for (int i = 0; i < t; i++) {
		int n, m, s, p, q, cnt=0;
		cin >> n >> m >> s;
		vector<vector<int> > map(m, vector<int>(n, 0));
		vector<vector<int> > ch(m, vector<int>(n, 0));
		queue<Loc> Q;

		for (int i = 0; i < s; i++) {
			cin >> q >> p;
			map[p][q] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1) {
					Q.push(Loc(i, j));
					map[i][j] = 0;
					while (!Q.empty()) {
						Loc tmp = Q.front();
						Q.pop();
						for (int i = 0; i < 4; i++) {
							int xx = tmp.x + dx[i];
							int yy = tmp.y + dy[i];

							if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
								if (map[xx][yy] == 1) {
									Q.push(Loc(xx, yy));
									map[xx][yy] = 0;
								}
							}
						}
					}
					cnt++;
				}
			}
		}
		res.push_back(cnt);
	}

	for (int i = 0; i < t; i++) {
		cout << res[i] << "\n";
	}
	return 0;
}
