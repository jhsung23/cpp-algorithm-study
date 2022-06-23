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
	int n, tmp;
	stack<int> cross; //교차로 스택
	vector<char> res; //POPO 이런거 담는용
	//입력받기
	cin>>n;
	vector<int> cars(n);
	for(int i=0;i<n;i++){
		cin>>cars[i];
	}
	vector<int> ans; //빠져나온 순서
	//첫번째만 넣어주기
	cross.push(cars[0]);
	res.push_back('P');

	for(int i=1;i<n;i++){
		while(!cross.empty() && cross.top()<cars[i]){
			tmp=cross.top();
			ans.push_back(tmp);
			if(ans.size()!=tmp){
				cout<<"impossible";
				return 0;
			}
			cross.pop();
			res.push_back('O');
		}
		cross.push(cars[i]);
		res.push_back('P');
	}
	while(!cross.empty()){
		tmp=cross.top();
		ans.push_back(tmp);
		cross.pop();
		res.push_back('O');
	}
	for(int i=0;i<res.size();i++){
		cout<<res[i];
	}
	return 0;
}
