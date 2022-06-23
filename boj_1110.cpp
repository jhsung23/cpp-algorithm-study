#include <iostream>
using namespace std;
int main()
{
	int newnumber, oldnumber;
	int initnumber;
	int ten, one;
	int cycle = 0;

	cin >> oldnumber;
	initnumber = oldnumber;

	while (true)
	{
		if (oldnumber < 10)
		{
			ten = oldnumber;
			one = oldnumber;
			newnumber = ten * 10 + one;
		}
		else
		{
			ten = oldnumber % 10;
			one = (oldnumber / 10 + oldnumber % 10) % 10;
			newnumber = ten * 10 + one;
		}
		cycle++;
		if (newnumber == initnumber)
			break;
		oldnumber = newnumber;
	}
	cout << cycle << endl;

	return 0;
}
