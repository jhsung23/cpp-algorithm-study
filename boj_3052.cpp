#include <iostream>
using namespace std;
int main()
{
	int remainder[42] = { 0 };
	int num[10];
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < 10; i++)
	{
		int j = num[i] % 42;
		remainder[j]++;
	}
	for (int i = 0; i < 42; i++)
	{
		if (remainder[i] != 0)
			count++;
	}
	cout << count << endl;
}
