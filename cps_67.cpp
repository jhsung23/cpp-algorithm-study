#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int map[30][30], ch[30], n, cost=2147000000;
void dfs(int v, int sum) {
	if (v == n) {
		if (sum < cost) cost = sum;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (map[v][i] > 0 && ch[i] == 0) {
				ch[i] = 1;
				dfs(i, sum + map[v][i]);
				ch[i] = 0;
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m, i, a, b, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		map[a][b] = c;
	}
	ch[1] = 1;
	dfs(1, 0);
	cout << cost << endl;

	return 0;

}
