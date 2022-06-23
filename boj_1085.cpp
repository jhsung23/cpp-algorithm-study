#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int minimum = min(x, y);
	int c = w - x;
	int d = h - y;
	minimum = min(minimum, c);
	minimum = min(minimum, d);
	cout << minimum << endl;
}
