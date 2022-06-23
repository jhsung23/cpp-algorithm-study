#include <iostream>
using namespace std;
int fibonacci(int i)
{
	if (i == 0) return 0;
	else if (i == 1) return 1;
	return fibonacci(i - 2) + fibonacci(i - 1);
}
int main() {
	int n;
	cin >> n;

	cout << fibonacci(n) << endl;
}
