#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<pair<int, int>> pairs;
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		pairs.push_back(make_pair(num1, num2));
	}
	sort(pairs.begin(), pairs.end());

	for (int i = 0; i < t; i++) {
		cout << pairs[i].first << " " << pairs[i].second << "\n";
	}
}
