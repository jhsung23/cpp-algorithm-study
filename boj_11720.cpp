#include <iostream>
#include <string>
using namespace std;
int main()
{
	int length;
	cin >> length;
	int sum = 0;

	string arr;
	cin >> arr;

	for (int i = 0; i < length; i++)
	{
		sum += (int)arr.at(i) - '0';
	}
	cout << sum;
}
