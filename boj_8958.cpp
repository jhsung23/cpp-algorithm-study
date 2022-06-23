#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int times;
	cin >> times;

	for (int i = 0; i < times; i++) {
		char ox[80];
		cin >> ox;
		int score[80] = { 0 };
		int total = 0;

		for (int k = 0; k < strlen(ox); k++) {
			if (ox[k] == 'O') {
				int j = k;
				while (ox[j] == 'O' && j>=0) {
					score[k]++;
					j--;
				}
			}
			total += score[k];
		}
		cout << total << endl;
	}
}
