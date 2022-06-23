#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

	int A, B, C;
	cin >> A >> B >> C;
	int n = 1;
	if (B >= C) {
		cout << -1 << endl;
	}
	else {
		cout << (A / (C - B) + 1) << endl;
	}
}
