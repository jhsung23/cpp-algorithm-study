#include <iostream>
using namespace std;

int map[30][30];
int ch[30];
int cnt = 0;
int n, m, a, b;

void dfs(int v) {
	if (v == n) {
		cnt++;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (map[v][i] == 1 && ch[i]!=1) {
				ch[i] = 1;
				dfs(i);
				ch[i] = 0;
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	ch[1] = 1;
	dfs(1);

	cout << cnt << endl;

	return 0;

}
