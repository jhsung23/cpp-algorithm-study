#include <iostream>
using namespace std;
int main()
{
	int a, b;

	while (true)
	{
		cin >> a >> b;
		if (b == 0)
			break;
		cout << a + b << endl;
	}
	return 0;
}
