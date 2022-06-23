#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int x1, x2, x3;
	int y1, y2, y3;
	int x, y;

	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	if (x1 == x2)
		x = x3;
	else if (x2 == x3)
		x = x1;
	else
		x = x2;

	if (y1 == y2)
		y = y3;
	else if (y2 == y3)
		y = y1;
	else
		y = y2;

	cout << x << " " << y << endl;

}
