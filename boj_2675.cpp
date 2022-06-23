#include <iostream>
#include <string>
using namespace std;
int main()
{
	int caseN;
	cin >> caseN;
	for (int i = 0; i < caseN; i++)
	{
		int repeat;
		cin >> repeat;
		string S;
		cin >> S;

		for (int j = 0; j < S.length(); j++)
		{
			for (int k = 0; k < repeat; k++)
			{
				cout << S[j];
			}
		}
		cout << endl;
	}
}
