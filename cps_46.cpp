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
	int n, k;
	cin>>n;
	vector<int> sec(n+1);
	queue<int> idx;
	for(int i=1;i<=n;i++){
		cin>>sec[i];
		idx.push(i);
	}
	cin>>k;
	while(k>0){
		int tmp=idx.front();
		if(sec[tmp]>0){
			sec[tmp]=sec[tmp]-1;
			k--;
		}
		idx.pop();
		if(sec[tmp]!=0) idx.push(tmp);
	}
	if(idx.empty()) cout<<-1;
	else cout<<idx.front();
	return 0;
}
