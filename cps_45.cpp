#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <string>
#include <queue>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, key;
	cin>>n>>key;
	queue<int> prince;
	vector<int> res(n);
	for(int i=1;i<=n;i++){
		prince.push(i);
	}
	while(prince.size()>0){
		for(int i=1;i<key;i++) {
			int tmp=prince.front();
			prince.push(tmp);
			prince.pop();
		}
		res.push_back(prince.front());
		prince.pop();
	}
	cout<<res.back();

	return 0;
}
