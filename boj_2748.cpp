#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<long long int> num(n+1);
	num[0] = 0;
	num[1] = 1;

	for (int i = 2; i <= n; i++) {
		num[i] = num[i - 1] + num[i - 2];
	}

	cout << num[n];
}
