#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	int count = 0;
	vector<int> numbers;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		numbers.push_back(num);
	}

	for (int j = 0; j < numbers.size(); j++) {
		bool flag = false;
		if (numbers[j] == 1) flag = true;
		for (int k = 2; k < numbers[j]; k++) {
			if (numbers[j] % k == 0) {
				flag = true;
			}
		}
		if (!flag) count++;
	}
	cout << count << endl;
}
