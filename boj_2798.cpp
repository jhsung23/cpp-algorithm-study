#include <iostream>
#include <vector>
using namespace std;
int main()
{
	//카드의 개수 n
	//최대숫자 m

	int n, m;
	cin >> n >> m;

	vector<int> numbers;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		numbers.push_back(a);
	}
	int total = 0;
	int temp;
	for (int i = 0; i < n-2; i++) {
		for (int j = i+1; j < n-1; j++) {
			for (int k = j+1; k < n; k++) {
				if (m - (numbers[i] + numbers[j] + numbers[k]) >= 0 &&
					m - (numbers[i] + numbers[j] + numbers[k]) < m - total) {
					total = numbers[i] + numbers[j] + numbers[k];
				}
			}
		}
	}
	cout << total << endl;
}
