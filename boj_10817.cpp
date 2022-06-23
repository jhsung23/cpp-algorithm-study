#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (a > b)
	{
		if (a > c)
		{
			if (b > c)
			{
				/*cout << a << b << c << endl;*/
				cout << b << endl;
			}
			else
			{
				/*cout << a << c << b << endl;*/
				cout << c << endl;
			}
		}
		else
		{
			/*cout << c << a << b << endl;*/
			cout << a << endl;
		}
	}
	else //(a<b)
	{
		if (a > c)
		{
			/*cout << b << a << c << endl;*/
			cout << a << endl;
		}
		else //(a<c)
		{
			if (b > c)
			{
				/*cout << b << c << a << endl;*/
				cout << c << endl;
			}
			else //(b<c)
			{
				/*cout << c << b << a << endl;*/
				cout << b << endl;
			}
		}
	}


	return 0;
}
