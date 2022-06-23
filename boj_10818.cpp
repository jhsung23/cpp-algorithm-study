#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int size;
	cin >> size;
	int num;
	vector <int> vec;

	for (int i = 0; i < size; i++)
	{
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	cout << vec[0] << " " << vec[size-1] << endl;
}
