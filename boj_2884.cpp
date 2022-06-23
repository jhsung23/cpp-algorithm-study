#include <iostream>
using namespace std;
int main()
{
	int h, m;
	cin >> h >> m;

	if (m <= 59 && m >= 45)
	{
		m -= 45;
		cout << h <<" "<< m << endl;
	}
	else if (m >= 0 && m < 45)
	{
		m += 60;
		m -= 45;
		if (h == 0)
			h = 23;
		else
			h--;
		cout << h << " " << m << endl;
	}
	return 0;
}
