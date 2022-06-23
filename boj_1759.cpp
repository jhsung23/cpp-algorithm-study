#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> vec;
vector<char> res;

bool isVowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
void fun(int lv, int next) {
	if (lv == l) {
		int cnt = count_if(res.begin(), res.end(), isVowel);
		if (cnt >= 1 && res.size() - cnt >= 2) {
			for (int i = 0; i < lv; i++) {
				cout << res[i];
			}
			cout << endl;
		}
	}
	else {
		for (int i = next; i < c; i++) {
			res[lv] = vec[i];
			fun(lv + 1, i + 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> l >> c;
	res.assign(l, 'a');
	for (int i = 0; i < c; i++) {
		char a;
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	fun(0,0);
}
