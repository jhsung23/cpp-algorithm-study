#include <iostream>
#include <queue>
using namespace std;

int n, a;
vector<int> num(12);
vector<bool> visited;
vector<int> res(12);
vector<int> opr;

priority_queue<int, vector<int>, greater<int> > pqgreater;
priority_queue<int> pqless;

void dp(int lv) {
	if (lv == n-1) {
		int ans = num[0];
		for (int i = 1; i < n; i++) {
			if (res[i - 1] == 0) ans += num[i];
			else if (res[i - 1] == 1) ans -= num[i];
			else if (res[i - 1] == 2) ans *= num[i];
			else if (res[i - 1] == 3) ans /= num[i];
		}
		pqgreater.push(ans);
		pqless.push(ans);
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			if (visited[i] == false) {
				res[lv] = opr[i];
				visited[i] = true;
				dp(lv + 1);
				visited[i] = false;
			}
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
		cin >> a;
		for (int j = 0; j < a; j++) {
			opr.push_back(i);
			visited.push_back(false);
		}
	}

	dp(0);

	cout << pqless.top() << "\n" << pqgreater.top();

	return 0;


}
