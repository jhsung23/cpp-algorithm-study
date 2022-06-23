#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int num;
	cin >> num;
	vector<int> reverse;
	while (num != 0) {
		reverse.push_back(num % 10);
		num /= 10;
	}
	sort(reverse.rbegin(), reverse.rend());
	for (int i = 0; i < reverse.size(); i++) {
		cout << reverse[i];
	}
}
