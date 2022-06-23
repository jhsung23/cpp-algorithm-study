#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int Q[100], front = -1, back = -1, ch[10];
vector<int> map[10];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, a, b, x;
	for (int i = 1; i <= 6; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	Q[++back] = 1;
	ch[1] = 1;
	while (front < back) {
		x = Q[++front];
		cout << x << " ";
		for (int i = 0; i < map[x].size(); i++) {
			if (ch[map[x][i]] == 0) {
				ch[map[x][i]] = 1;
				Q[++back] = map[x][i];
			}
		}
	}


	return 0;

}
