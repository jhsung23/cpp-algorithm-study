#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int ch[30], n, cnt, sum = 0, cost = 2147000000;
vector<pair<int, int> > map[30];
void dfs(int v, int sum) {
	if (v==n) {
		if (sum < cost) cost = sum;
	}
	else {
		for (int i = 0; i < map[v].size(); i++) {
			if (ch[map[v][i].first] == 0) {
				ch[map[v][i].first] = 1;
				dfs(map[v][i].first, sum + map[v][i].second);
				ch[map[v][i].first] = 0;
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m, a, b, c;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
	}

	ch[1] = 1;
	dfs(1, 0);
	cout << cost << endl;

	return 0;

}
