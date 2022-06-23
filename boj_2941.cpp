#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	//c d l n s z
	const int SIZE = 100;
	char croatia[SIZE];
	int count = 0;
	cin >> croatia;

	for (int i = 0; i < strlen(croatia); i++) {
		if (croatia[i] == 'c') {
			if (croatia[i + 1] == '=') {
				count++;
				i += 1;
			}
			else if (croatia[i + 1] == '-') {
				count++;
				i += 1;
			}
			else count++;
		}
		else if (croatia[i] == 'd') {
			if (croatia[i + 1] == 'z') {
				if (croatia[i + 2] == '=') {
					count++;
					i += 2;
				}
				else {
					count += 2;
					i += 1;
				}
			}
			else if (croatia[i + 1] == '-') {
				count++;
				i += 1;
			}
			else count++;
		}
		else if (croatia[i] == 'l') {
			if (croatia[i + 1] == 'j') {
				count++;
				i += 1;
			}
			else count++;
		}
		else if (croatia[i] == 'n') {
			if (croatia[i + 1] == 'j') {
				count++;
				i += 1;
			}
			else count++;
		}
		else if (croatia[i] == 's') {
			if (croatia[i + 1] == '=') {
				count++;
				i += 1;
			}
			else count++;
		}
		else if (croatia[i] == 'z') {
			if (croatia[i + 1] == '=') {
				count++;
				i += 1;
			}
			else count++;
		}
		else count++;

	}
	cout << count << endl;
}
