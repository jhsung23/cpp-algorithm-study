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

	int map[7][7], dis[7][7], res=2147000000;
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cin >> map[i][j];
		}
	}

	dis[0][0] = 0;
	queue<Loc> Q;

	Q.push(Loc(0, 0));
	map[0][0] = 1;
	while (!Q.empty()) {
		Loc tmp = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = tmp.x + dx[i];
			int yy = tmp.y + dy[i];

			if (map[xx][yy]==0 && xx >= 0 && xx <= 6 && yy >= 0 && yy <= 6) {
				Q.push(Loc(xx, yy));
				map[xx][yy] = 1;
				dis[xx][yy] = dis[tmp.x][tmp.y] + 1;
			}
		}
	}
	if (dis[6][6] == 0) cout << -1 << "\n";
	else cout << dis[6][6] << "\n";

	return 0;
}
