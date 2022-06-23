#include <iostream>
#include <vector>
using namespace std;
int sum(vector<int> numbers)
{
	int total = 0;
	for (int i = 0; i < numbers.size(); i++) {
		total += numbers[i];
	}
	return total;
}
int main()
{
	int m, n;
	cin >> m >> n;
	//m이상 n이하
	vector<int> sosu;

	for (int i = m; i <= n; i++) {
		bool flag = true;
		if (i == 1) flag = false;
		for (int k = 2; k < i; k++) {
			if (i%k == 0) {
				flag = false;
			}
		}
		if (flag) sosu.push_back(i);
	}

	if (sosu.size() == 0) cout << -1 << endl;
	else {
		//숫자들의 합 구하기
		cout << sum(sosu) << endl;
		cout << sosu[0] << endl;
	}

}
