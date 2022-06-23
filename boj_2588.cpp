#include <iostream>
using namespace std;
int main()
{
	int x;
	int y;

	cin >> x >> y;

	int a = x * (y % 10);
	int b = x * ((y / 10) % 10);
	int c = x * (y / 100);
	int d = x * y;

	cout << a << endl << b << endl << c << endl << d << endl;

	return 0;
}
