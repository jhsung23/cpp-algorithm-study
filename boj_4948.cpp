#include <iostream>
using namespace std;
int main()
{
	while (true) {
		int n;
		cin >> n;
		if (n == 0) return 0;
		int count = 0;
		//n초과 2n이하
		bool sosu[123456 * 2];

		for (int i = 2; i <= 2*n; i++) {
			sosu[i] = true;
		}

		for (int i = 2; i <= 2 * n; i++) {
			for (int k = i * 2; k <= 2 * n; k += i) {
				sosu[k] = false;
			}
		}

		for (int i = n + 1; i <= 2 * n; i++) {
			if (sosu[i]) count++;
		}
		cout << count << endl;
	}
}
