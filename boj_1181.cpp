#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool compare(string s1, string s2) {
	if (s1.length() == s2.length()) {
		return s1 < s2;
	}
	return s1.length() < s2.length();
}
int main()
{
	int t;
	cin >> t;
	vector<string> words;

	for (int i = 0; i < t; i++) {
		string w;
		cin >> w;
		if (find(words.begin(), words.end(), w) == words.end()) {
			words.push_back(w);
		}
	}

	sort(words.begin(), words.end(), compare);
	//print
	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << "\n";
	}
	return 0;
}
