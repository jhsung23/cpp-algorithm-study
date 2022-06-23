#include <iostream>
using namespace std;
int main()
{
	int casenum;
	cin >> casenum;
	int studentNum;
	double ratio[1000];
	double average;
	for (int i = 0; i < casenum; i++)
	{
		cin >> studentNum;
		int* case1 = new int[studentNum];
		double sum = 0;
		for (int j = 0; j < studentNum; j++)
		{
			cin >> case1[j];
			sum += case1[j];
		}
		average = sum / (double)studentNum;
		double count = 0;
		for (int l = 0; l < studentNum; l++)
		{
			if (case1[l] > average)
				count++;
		}
		ratio[i] = count / (double)studentNum * 100;
	}
	for (int i = 0; i < casenum; i++)
	{
		cout << fixed;
		cout.precision(3);
		cout << ratio[i] << "%" << endl;
	}
}
