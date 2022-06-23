#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int times;
	cin >> times;
	int x1, y1, r1;
	int x2, y2, r2;

	for (int t = 0; t < times; t++) {
		cin >> x1 >> y1 >> r1;
		cin >> x2 >> y2 >> r2;

		double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << endl;
		}
		else if (d > r1 + r2 || abs(r1 - r2) > d || (d == 0 && r1!=r2)) {
			cout << 0 << endl;
		}
		else if (abs(r1 - r2) == d || r1 + r2 == d) {
			cout << 1 << endl;
		}
		else if (abs(r1 - r2) < d && r1 + r2 > d) {
			cout << 2 << endl;
		}
	}
}
