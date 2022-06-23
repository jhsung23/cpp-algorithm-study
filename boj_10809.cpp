#include <iostream>
#include <string>
using namespace std;
int main()
{
	string S;
	cin >> S;

	string alpha = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < alpha.length(); i++)
	{
		if (S.find(alpha[i]) == string::npos)
			cout << -1 << " ";
		else
			cout << S.find(alpha[i]) << " ";
	}
}
