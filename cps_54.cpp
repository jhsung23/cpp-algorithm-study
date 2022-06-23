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
	stack<char> S;
	char str[31];
	cin>>str;
	for(int i=0;str[i]!='\0';i++){
		if(str[i]=='(') S.push('(');
		else{
			if(S.empty()){
				cout<<"NO";
				return 0;
			}else S.pop();
		}
	}
	if(S.empty()) cout<<"YES";
	else cout<<"NO";
	return 0;
}
