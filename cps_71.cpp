#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ch[10001], d[3] = { +1, -1, +5 };
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int s, e, pos;
	queue<int> Q;
	cin >> s >> e;

	ch[s] = 1;
	Q.push(s);
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (int i = 0; i < 3; i++) {
			pos = x + d[i];
			if(pos<=0 || pos>10000) continue;
			if (pos == e) {
				cout << ch[x] << "\n";
				return 0;
			}
			if (ch[pos] == 0) {
				ch[pos] = ch[x] + 1;
				Q.push(pos);
			}
		}
	}

	return 0;

}
