#include <iostream>
#include <utility>
using namespace std;
int main()
{
	pair<int, int> people[50];

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> people[i].first >> people[i].second;
	}
	for (int i = 0; i < n; i++) {
		int rank = 1;
		for (int j = 0; j < n; j++) {
			if (people[i].first < people[j].first &&
				people[i].second < people[j].second) {
				rank++;
			}
		}
		cout << rank << " ";
	}

}
