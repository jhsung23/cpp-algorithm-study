#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int n, ch[16], res=-2147000000;
vector<pair<int, int> > sch;
void dfs(int day, int money) {
	if (day==n+1) {
		if (res < money) res = money;
	}
	else {
		if(day+sch[day].first<=n+1) dfs(day + sch[day].first, money + sch[day].second);
		dfs(day + 1, money);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	sch.push_back(make_pair(0, 0));
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		sch.push_back(make_pair(a, b));
	}

	dfs(1, 0);
	cout << res << endl;
}
