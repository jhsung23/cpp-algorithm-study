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

	int n, map[30][30], cnt = 0;
	int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
	int dy[8] = { -1,-1,0,1,1,1,0,-1 };
	queue<Loc> Q;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				Q.push(Loc(i, j));
				map[i][j] = 0;
				while (!Q.empty()) {
					Loc tmp = Q.front();
					Q.pop();
					for (int i = 0; i < 8; i++) {
						int xx = tmp.x + dx[i];
						int yy = tmp.y + dy[i];
						if (map[xx][yy] == 1) {
							Q.push(Loc(xx, yy));
							map[xx][yy] = 0;
						}
					}
				}
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
