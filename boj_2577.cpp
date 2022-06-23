#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int result = a * b * c;

	int count[10] = { 0 };
	int one;

	while (result != 0)
	{
		one = result % 10;
		count[one]++;
		result = result / 10;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << count[i] << endl;
	}
}
