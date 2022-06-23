#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a;
	cin >> a;
	int b;
	cin >> b;

	int a1_3 = a % 10;
	a /= 10;
	int a2_2 = a % 10;
	a /= 10;
	int a3_1 = a;
	int newA = a1_3 * 100 + a2_2 * 10 + a3_1;

	int b1_3 = b % 10;
	b /= 10;
	int b2_2 = b % 10;
	b /= 10;
	int b3_1 = b;
	int newB = b1_3 * 100 + b2_2 * 10 + b3_1;

	if (newA > newB)
		cout << newA << endl;
	else
		cout << newB << endl;

}
