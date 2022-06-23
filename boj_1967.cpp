#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int n, ep, res = -2147000000;
vector<pair<int, int> > tree[10001];
vector<bool> visited(10001, false);

void dfs(int v, int sum) {

	if (visited[v] == true) return;

	visited[v] = true;

	if (sum > res) {
		res = sum;
		ep = v;
	}

	for (int i = 0; i < tree[v].size(); i++) {
		int next = tree[v][i].first;
		dfs(next, sum + tree[v][i].second);
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back(make_pair(b, c));
		tree[b].push_back(make_pair(a, c));
	}

	dfs(1, 0);

	visited = vector<bool>(10001, false);
	dfs(ep, 0);

	cout << res;

	return 0;
}
