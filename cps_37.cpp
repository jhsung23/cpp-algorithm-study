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
	int size, n, a;
	bool flag;
	cin>>size>>n;
	vector<int> num(size);
	for(int i=0;i<n;i++){
		cin>>a;
		int idx;
		flag=false;
		for(int j=size-1;j>=0;j--){
			if(num[j]==a){
				flag=true;
				idx=j;
			}
		}
		if(flag){
			for(int k=idx;k>=1;k--){
				num[k]=num[k-1];
			}
		} else {
			for(int k=size-1;k>=1;k--){
				num[k]=num[k-1];
			}
		}
		num[0]=a;
	}
	for(int k=0;k<size;k++){
		cout<<num[k]<<" ";
	}

	return 0;
}
