#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int n, num[11], oper[4];
int maxi = -2147000000, mini = 2147000000;
void dfs(int s, int res) {
	if (s==n) {
		if (mini > res) mini = res;
		if (maxi < res) maxi = res;
	}
	else {
		if (oper[0] > 0) {
			oper[0] -= 1;
			dfs(s + 1, res + num[s]);
			oper[0] += 1;
		}
		if (oper[1] > 0) {
			oper[1] -= 1;
			dfs(s + 1, res - num[s]);
			oper[1] += 1;
		}
		if (oper[2] > 0) {
			oper[2] -= 1;
			dfs(s + 1, res * num[s]);
			oper[2] += 1;
		}
		if (oper[3] > 0) {
			oper[3] -= 1;
			dfs(s + 1, res / num[s]);
			oper[3] += 1;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	dfs(1, num[0]);
	cout << maxi << "\n" << mini;

}
