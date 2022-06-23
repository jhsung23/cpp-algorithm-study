#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
vector<int> tree[100001];
vector<int> parent(100001);
vector<bool> visited(100001, false);

void dfs(int v) {
	visited[v] = true;

	for (int i = 0; i < tree[v].size(); i++) {
		int next = tree[v][i];
		if (!visited[next]) {
			parent[next] = v;
			dfs(next);
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}
