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
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(), a.end());

	cin>>m;
	vector<int> b(m);
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	sort(b.rbegin(), b.rend());

	vector<int> c(n+m);
	for(int i=0;i<n;i++){
		c[i]=a[i];
	}
	for(int i=0;i<m;i++){
		c[n+i]=b[i];
	}

	int start=0, end=n+m-1;
	vector<int> res;
	while(start<end){
		if(c[start]==c[end]){
			res.push_back(c[start]);
			start++;
			end--;
		} else if(c[start]<c[end]){
			start++;
		} else end--;
	}

	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}

	return 0;
}
