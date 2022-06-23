#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;

	if (n < 3) cout << -1 << endl;

	int q;
	int bigQ = n / 5;
	while (bigQ >= 0) {
		int temp = n - bigQ * 5;
		if (temp % 3 == 0) {
			q = bigQ + temp / 3;
			cout << q << endl;
			return 0;
		}
		else {
			bigQ--;
		}
	}
	cout << -1 << endl;
}
