#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int subnum;
	cin >> subnum;
	double M = 0;
	double sum = 0;

	vector<double> score;
	for (int i = 0; i < subnum; i++)
	{
		double s;
		cin >> s;
		score.push_back(s);
	}
	for (int i = 0; i < subnum; i++)
	{
		if (score[i] > M)
		{
			M = score[i];
		}
	}
	for (int i = 0; i < subnum; i++)
	{
		score[i] = score[i] / M * 100;
		sum += score[i];
	}
	double average = sum / subnum;
	cout << fixed;
	cout.precision(2);
	cout << average << endl;

}
