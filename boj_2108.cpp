#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	vector<int> numbers;
	int count[8001] = { 0 };
	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		numbers.push_back(num);
		count[num + 4000] += 1;
	}
	//산술평균
	double avg;
	double sum = 0;
	for (int i = 0; i < t; i++) {
		sum += numbers[i];
	}
	avg = sum / t;
	cout << round(avg) << "\n";

	//중앙값
	sort(numbers.begin(), numbers.end());
	cout << numbers[t / 2] << "\n";
	//최빈값
	int frq;
	int maxFrq = 0;
	int tmpIdx;
	for (int i = 0; i < 8001; i++) {
		if (count[i] > maxFrq) {
			maxFrq = count[i];
			tmpIdx = i;
			frq = i - 4000;
		}
	}
	for (int i = 0; i < 8001; i++) {
		if (count[i] == maxFrq && tmpIdx < i) {
			frq = i - 4000;
			break;
		}
	}
	cout << frq << "\n";

	//범위 (가장큰수-가장작은수)
	int range = numbers[t-1] - numbers[0];
	cout << range << "\n";
}
