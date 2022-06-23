#include <iostream>
#include <string>
using namespace std;
int main()
{
	string word;
	cin >> word;

	for (int i = 0; i < word.size(); i++)
	{
		word[i] = toupper(word[i]);
	}

	int count[26] = { 0, };
	for (int i = 0; i < word.size(); i++)
	{
		int idx = int(word[i]) - 65;
		count[idx]++;
	}
	int biggest = 0;
	int biggestidx = 0;
	for (int i = 0; i < 26; i++)
	{
		if (count[i] > biggest)
		{
			biggest = count[i];
			biggestidx = i;
		}
	}
	for (int i = biggestidx + 1; i < 26; i++)
	{
		if (count[i] == biggest && i != biggestidx)
		{
			cout << "?" << endl;
			return 0;
		}
	}
	cout << static_cast<char>(biggestidx+65) << endl;

}
