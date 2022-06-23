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
	freopen("input.txt", "rt", stdin);
	int a;
	priority_queue<int> pQ;
	while(true){
		cin>>a;
		if(a==-1) break;
		if(a==0){
			if(pQ.empty()) cout<<-1;
			else{
				cout<<pQ.top()<<"\n";
				pQ.pop();
			}
		}
		else pQ.push(a);
	}
	return 0;
}
