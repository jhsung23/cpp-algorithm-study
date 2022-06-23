#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	const double PI = 3.14159265358979;
	int r;
	cin >> r;
	double u = r * r*PI;
	double t = 2 * r*r;

	cout << fixed;
	cout.precision(6);
	cout << u << endl;
	cout << t << endl;
}
