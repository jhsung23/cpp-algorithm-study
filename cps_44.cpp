#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <string>
using namespace std;
int m, horse;
vector<int> magoogan;
bool Ok(int mid){
	int mal=1;
	int p=0, q=1;
	while(q<m){
		if(magoogan[q]-magoogan[p]>=mid){
			p=q;
			q=p+1;
			mal++;
		}else{
			q++;
		}
	}
	if(mal>=horse) return true;
	else return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int p, q, mid, res;
	cin>>m>>horse;
	for(int i=0;i<m;i++){
		int a;
		cin>>a;
		magoogan.push_back(a);
	}
	sort(magoogan.begin(), magoogan.end());
	p=magoogan[0];
	q=magoogan[m-1];
	while(p<=q){
		mid=(p+q)/2;
		if(Ok(mid)){
			res=mid;
			p=mid+1;
		}else{
			q=mid-1;
		}
	}
	cout<<res<<endl;
	return 0;
}
