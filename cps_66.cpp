#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int ch[30], cnt = 0, n;
vector<int> map[30];
void dfs(int v) {
	if (v == n) {
		cnt++;
	}
	else {
		for (int i = 0; i < map[v].size(); i++) {
			if (ch[map[v][i]]==0) {
				ch[map[v][i]] = 1;
				dfs(map[v][i]);
				ch[map[v][i]] = 0;
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int m, i, j, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
	}

	ch[1] = 1;
	dfs(1);
	cout << cnt << endl;

	return 0;

}
