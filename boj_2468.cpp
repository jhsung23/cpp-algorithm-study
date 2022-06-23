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

	int n, res=-1, highest=-2147000000, lowest=2147000000;
	cin >> n;

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	vector<vector<int> > map(n, vector<int>(n, 0));
	queue<Loc> Q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] < lowest) lowest = map[i][j];
			else if (map[i][j] > highest) highest = map[i][j];
		}
	}

	for (int t = lowest-1; t < highest; t++) {
		vector<vector<int> > ch(n, vector<int>(n, 0));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] <= t) ch[i][j] = 0;
				else ch[i][j] = 1;
			}
		}

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << ch[i][j] << " ";
			}
			cout << endl;
		}*/
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ch[i][j] == 1) {
					Q.push(Loc(i, j));
					ch[i][j] = 0;

					while (!Q.empty()) {
						Loc tmp = Q.front();
						Q.pop();

						for (int i = 0; i < 4; i++) {
							int xx = tmp.x + dx[i];
							int yy = tmp.y + dy[i];

							if (xx >= 0 && xx < n && yy >= 0 && yy < n) {
								if (ch[xx][yy] == 1) {
									Q.push(Loc(xx, yy));
									ch[xx][yy] = 0;
								}
							}
						}
					}
					cnt++;
				}
			}
		}
		//cout << cnt << endl;
		if (cnt > res) res = cnt;

	}

	cout << res;
	//if (res == -1) cout << 1;
	//else cout << res;

	return 0;
}
