#include <iostream>
using namespace std;
int main()
{
	int num[9];

	for (int i = 0; i < 9; i++)
	{
		cin >> num[i];
	}
	int max = 0;
	int index;

	for (int j = 0; j < 9; j++)
	{
		if (num[j] > max)
		{
			max = num[j];
			index = j + 1;
		}
	}
	cout << max << endl << index << endl;
}
