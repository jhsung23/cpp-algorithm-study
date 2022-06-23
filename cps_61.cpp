#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;
int n, m, num[11], cnt=0;
void dfs(int lv, int sum) {
	if (lv == n+1) {
		if (sum == m) cnt++;
	}
	else {
		dfs(lv + 1, sum + num[lv]);
		dfs(lv + 1, sum - num[lv]);
		dfs(lv + 1, sum);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	dfs(1, 0);
	cout << cnt << "\n";
}
