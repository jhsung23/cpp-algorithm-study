#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isHansu(int num)
{
	int count = 0;
	bool flag = true;
	vector<int> temp;
	if (num < 10) return flag;

	while (num != 0) {
		temp.push_back(num % 10);
		num /= 10;
	}
	reverse(temp.begin(), temp.end());
	int d = temp[temp.size()-1] - temp[temp.size()-2];
	for (int i = 0; i < temp.size()-1; i++) {
		if (temp[i + 1] - temp[i] != d) {
			flag = false;
		}
	}
	return flag;
}
int main() {
	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (isHansu(i)) count++;
	}
	cout << count << endl;
}
