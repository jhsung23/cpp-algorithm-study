#include <iostream>
#include <string>
using namespace std;
int main()
{
	string sntnc;
	getline(cin, sntnc);
	int count = 1;
	int size = sntnc.size();

	if (sntnc[0] == ' ')
	{
		count = 0;
	}
	for (int i = 0; i < sntnc.size(); i++)
	{
		if (sntnc[i] == ' ')
		{
			count++;
		}
	}
	if (sntnc[size-1] == ' ')
	{
		count--;
	}
	cout << count << endl;

}
