#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ch[30], dis[30];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b, x;
	vector<int> map[30];
	queue<int> Q;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
	}

	Q.push(1);
	ch[1];
	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		for (int i = 0; i < map[x].size(); i++) {
			if (ch[map[x][i]] == 0) {
				ch[map[x][i]] = 1;
				Q.push(map[x][i]);
				dis[map[x][i]] = dis[x] + 1;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << i << " : " << dis[i] << "\n";
	}

	return 0;

}
