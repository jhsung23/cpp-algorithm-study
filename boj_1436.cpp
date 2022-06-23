#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;

	int init = 666;
	int count = 0;
	string title;
	while (1) {
		title = to_string(init);
		if (title.find("666") != -1) {
			count += 1;
		}
		if (count == n) {
			cout << title << endl;
			break;
		}
		else init++;
	}

}
