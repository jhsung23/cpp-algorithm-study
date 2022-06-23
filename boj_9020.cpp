#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	const int SIZE = 10001;
	bool sosu[SIZE] = { false };

	for (int i = 2; i < SIZE; i++) {
		sosu[i] = true;
	}

	for (int i = 2; i < SIZE; i++) {
		for (int k = i * 2; k < SIZE; k += i) {
			sosu[k] = false;
		}
	}

	int times;
	cin >> times;
	for (int t = 0; t < times; t++) {
		int num;
		cin >> num;
		int temp1, temp2;
		int a, b;
		int mintemp = num;

		for (int i = 2; i <= num/2; i++) {
			if (sosu[i] && sosu[num - i]) {
				temp1 = i;
				temp2 = num - i;
				if (mintemp > abs(temp1 - temp2)) {
					mintemp = abs(temp1 - temp2);
					a = temp1;
					b = temp2;
				}
			}
		}
		cout << a << " " << b << endl;
	}
}
