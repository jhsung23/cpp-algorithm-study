#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int a, b;

	for (int i = 0; i < t; i++)
	{
		cin.tie(NULL);
		cin >> a >> b;
		cout.sync_with_stdio(false);
		cout << a + b << "\n";
	}

	return 0;
}
