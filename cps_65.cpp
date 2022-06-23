#include <iostream>
#include <string.h>
using namespace std;
int map[9][9], cnt = 0;
int ch[9][9];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void dfs(int a, int b) {
	if (a==7 && b==7) {
		cnt++;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (map[a + dx[i]][b + dy[i]] == 0
				&& ch[a + dx[i]][b + dy[i]] == 0) {
				ch[a + dx[i]][b + dy[i]] = 1;
				dfs(a + dx[i], b + dy[i]);
				ch[a + dx[i]][b + dy[i]] = 0;
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fill(map[0], map[0]+81, 1);
	fill(ch[0], ch[0]+81, 1);

	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
			cin >> map[i][j];
			ch[i][j] = 0;
		}
	}

	ch[1][1] = 7;
	dfs(1, 1);

	cout << cnt << endl;

	return 0;

}
