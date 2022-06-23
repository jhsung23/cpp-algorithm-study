#include <iostream>
using namespace std;
int main()
{
	int n, sum;
	cin >> n; //n을 만드는 자연수 중에 가장 작은거
	for (int i = 1; i < 1000000; i++) {
		int temp = i;
		sum = i;
		while (temp != 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == n) {
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}
