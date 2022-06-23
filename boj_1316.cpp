#include <iostream>
#include <string>
using namespace std;
int main()
{
	int times;
	int count = 0;
	cin >> times;
	//happy

	for (int n = 0; n < times; n++) {
		bool flag = true;
		string word;
		cin >> word;
		for (int i = 0; i < word.length(); i++) {
			for (int j = 0; j < i; j++) {
				if (word[i] != word[i - 1] && word[i] == word[j]) {
					flag = false;
				}
			}
		}
		if (flag) count++;
	}

	cout << count << endl;

}
