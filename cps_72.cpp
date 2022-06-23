#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	int n,k;
	cin>>n>>k;
	queue<int> prince;
	for(int i=1;i<=n;i++){
		prince.push(i);
	}
	while(prince.size()!=1){
		for(int i=0;i<k-1;i++){
			int tmp=prince.front();
			prince.pop();
			prince.push(tmp);
		}
		prince.pop();
	}
	cout<<prince.front();
	return 0;
}
