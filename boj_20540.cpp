#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<pair<char, char>> MBTI;
	MBTI.push_back(make_pair('E', 'I'));
	MBTI.push_back(make_pair('S', 'N'));
	MBTI.push_back(make_pair('T', 'F'));
	MBTI.push_back(make_pair('J', 'P'));

	string mbti;
	cin >> mbti;
	for (int i = 0; i < 4; i++) {
		if (mbti[i]==MBTI[i].first) {
			cout << MBTI[i].second;
		}
		else {
			cout << MBTI[i].first;
		}
	}
}
