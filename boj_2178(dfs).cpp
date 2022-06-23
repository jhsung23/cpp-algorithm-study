#include <iostream>
#include <string.h>
using namespace std;
int n, m, cnt, mini=10001;
char map[102][102];
int ch[102][102];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void dfs(int a, int b, int cnt) {

	if (a<0 || a>n || b<0 || b>m) return;
	if (a==n-1 && b==m-1) {
		if (cnt < mini) mini = cnt;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int x = a + dx[i];
			int y = b + dy[i];
			if (map[x][y] == '1'
				&& ch[x][y] == 0) {
				ch[x][y] = 1;
				dfs(x, y, cnt+1);
				ch[x][y] = 0;
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	ch[0][0] = 1;
	dfs(0, 0, 1);
	cout << mini << endl;

	return 0;

}
