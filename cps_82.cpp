#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int n, r, cnt=0;
int arr[20], res[20], ch[20];

void dfs(int lv) {
	if (lv == r) {
		for (int i = 0; i < lv; i++) {
			cout << res[i] << " ";
		}
		cnt++;
		cout << "\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			if (ch[i] == 0) {
				res[lv] = arr[i];
				ch[i] = 1;
				dfs(lv + 1);
				ch[i] = 0;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a;
	cin >> n >> r;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(0);
	cout << cnt;

}
