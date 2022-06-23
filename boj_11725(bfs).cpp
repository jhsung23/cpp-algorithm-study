#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n;
vector<int> tree[100001];
vector<int> parent(100001);
vector<bool> visited(100001, false);
queue<int> Q;

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

	Q.push(1);
	visited[1] = true;
	while (!Q.empty()) {
		int tmp = Q.front();
		Q.pop();
		for (int i = 0; i < tree[tmp].size(); i++) {
			int next = tree[tmp][i];
			if (!visited[next]) {
				visited[next] = true;
				Q.push(next);
				parent[next] = tmp;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}
