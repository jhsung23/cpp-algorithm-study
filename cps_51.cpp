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
	vector<vector<int> > field(w+2, vector<int> (h+2));
	vector<vector<int> > dy(w+2, vector<int> (h+2));
	for(int i=1;i<h+1;i++){
		for(int j=1;j<w+1;j++){
			cin>>field[i][j];
			dy[i][j]=dy[i][j-1]+dy[i-1][j]-dy[i-1][j-1]+field[i][j];
		}
	}
	cin>>height>>width;
	int tmp, maxi=0;
	for(int i=height;i<h+1;i++){
		for(int j=width;j<w+1;j++){
			tmp=dy[i][j]-dy[i][j-width]-dy[i-height][j]+dy[i-height][j-width];
			if(tmp>maxi) maxi=tmp;
		}
	}

	cout<<maxi;

	return 0;
}
