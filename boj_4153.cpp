#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int x, y, z;
	int arr[3];
	while (true) {
		cin >> x >> y >> z;
		if (x == 0 && y == 0 && z == 0) return 0;
		arr[0] = x;
		arr[1] = y;
		arr[2] = z;
		sort(arr, arr + 3);
		if (pow(arr[2], 2) == pow(arr[0], 2) + pow(arr[1], 2)) cout << "right" << endl;
		else cout << "wrong" << endl;
	}
}
