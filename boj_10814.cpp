#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool compare(pair<int, string> a, pair<int, string> b)
{
	if (a.first < b.first) return true;
	else return false;
}
int main()
{
	int t;
	cin >> t;
	vector<pair<int, string>> members;

	for (int i = 0; i < t; i++) {
		int age;
		string name;
		cin >> age >> name;
		members.push_back(make_pair(age, name));
	}
	stable_sort(members.begin(), members.end(), compare);
	//print
	for (int i = 0; i < members.size(); i++) {
		cout << members[i].first << " " << members[i].second << "\n";
	}
	return 0;
}
