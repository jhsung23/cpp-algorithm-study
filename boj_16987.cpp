#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, res=-2147000000;
//priority_queue<int, vector<int> > pq;
vector<pair<int, int> > egg; //pair<내구도 d, 무게 w>

//3
//1 100 -> -4
//8 5 -> -92
//3 5

//1 100 -> -4
//8 5
//3 5 -> -97

void fun(int lv) {
	if (lv==n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (egg[i].first <= 0) cnt++;
		}
		if (cnt > res) res = cnt;
	}
	else {
		if (egg[lv].first > 0) { //손에 쥔 달걀이 깨진건지 아닌지 확인
			int ch = 0;
			for (int i = 0; i < n; i++) {
				if (i != lv) {
					if (egg[i].first > 0) {
						egg[i].first -= egg[lv].second;
						egg[lv].first -= egg[i].second;
						fun(lv + 1);
						egg[i].first += egg[lv].second;
						egg[lv].first += egg[i].second;
					}
					else {
						ch++;
					}
				}
			}
			if (ch == n - 1) fun(lv + 1);
		}
		else {
			fun(lv + 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		egg.push_back(make_pair(d, w));
	}

	fun(0);

	cout << res;
}
