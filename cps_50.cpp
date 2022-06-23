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
	int h, w, height, width;
	cin>>h>>w;
	vector<vector<int> > field(w, vector<int> (h));
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>field[i][j];
		}
	}
	cin>>height>>width;

	int res, maxi=0;
	for(int p=0;p<=h-height;p++){
		for(int q=0;q<=w-width;q++){
			res=0;
			for(int i=p;i<p+height;i++){
				for(int j=q;j<q+width;j++){
					res+=field[i][j];
				}
			}
			if(res>maxi) maxi=res;
		}
	}
	cout<<maxi;
	return 0;
}
