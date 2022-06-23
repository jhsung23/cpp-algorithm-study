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
   //스택 stl 사용하여 구현
	int n, k;
	char str[20]="0123456789ABCDEF";
	stack<int> S;
	cin>>n>>k;

	while(n!=0){
		S.push(n%k);
		n/=k;
	}
	while(!S.empty()){
		cout<<str[S.top()];
		S.pop();
	}

	return 0;
}
