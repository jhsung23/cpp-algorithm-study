#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, m;
	cin>>n>>m;
	vector<int> num(n);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num.begin(), num.end());

	int p=0, q=n-1;
	while(p<=q){
		int t=(p+q)/2;
		if(m>num[t]){
			p=t+1;
		}else if(m<num[t]){
			q=t-1;
		}else{
			cout<<t+1;
			return 0;
		}
	}
	return 0;
}
