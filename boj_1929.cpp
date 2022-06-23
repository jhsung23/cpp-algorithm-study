#include <iostream>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	//m이상 n이하
	bool sosu[1000001];

	for (int i = m; i <= n; i++) {
		sosu[i] = true;
	}
	if (m == 1) sosu[m] = false;

	for (int i = 2; i <= n; i++) {
		for (int k = i * 2; k <= n; k += i) {
			sosu[k] = false;
		}
	}

	for (int i = m; i <= n; i++) {
		if (sosu[i] == true)
			cout << i << "\n";
	}
}
