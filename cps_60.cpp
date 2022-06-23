#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;
int n, num[11], total = 0;
bool flag = false;
void dfs(int lv, int sum) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	if (sum > (total / 2)) return;
	if (flag) return;
	if (lv == n + 1) {
		if (sum == (total - sum)) {
			flag = true;
		}
	}
	else {
		dfs(lv + 1, sum + num[lv]);
		dfs(lv + 1, sum);
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		total += num[i];
	}
	dfs(1, 0);

	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
