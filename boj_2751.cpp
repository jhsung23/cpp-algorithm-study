#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	vector<int> numbers;
	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		numbers.push_back(num);
	}
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < t; i++) {
		cout << numbers[i] << '\n';
	}
}
