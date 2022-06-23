#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, p2=1, p3=1, p5=1, tmpmin;
	cin>>n;
	int a[1501];
	a[1]=1;
	for(int i=2;i<n+1;i++){
		if(a[p2]*2<a[p3]*3) tmpmin=a[p2]*2;
		else tmpmin=a[p3]*3;
		if(a[p5]*5<tmpmin) tmpmin=a[p5]*5;

		if(tmpmin==a[p2]*2) p2++;
		if(tmpmin==a[p3]*3) p3++;
		if(tmpmin==a[p5]*5) p5++;
		a[i]=tmpmin;
	}
	cout<<a[n];
	return 0;
}
