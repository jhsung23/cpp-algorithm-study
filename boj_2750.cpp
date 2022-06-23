#include <iostream>
#include <vector>
using namespace std;
void insertion_sort(vector<int> num, int size)
{
	int i, j, key;
	for (i = 0; i < size; i++) {
		key = num[i];
		for (j = i; j > 0; j--) {
			if (num[j - 1] > key) {
				num[j] = num[j - 1];
			}
			else break;
		}
		num[j] = key;
	}

	for (int n = 0; n < size; n++) {
		cout << num[n] << endl;
	}
}
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
	insertion_sort(numbers, t);

}
