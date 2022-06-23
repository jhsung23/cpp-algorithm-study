#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <string>
#include <queue>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, cnt=0;
	cin>>n;
	vector<vector<int> > map(n+2, vector<int> (n+2));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>map[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(map[i][j]>map[i-1][j] &&
			map[i][j]>map[i+1][j] &&
			map[i][j]>map[i][j-1] &&
			map[i][j]>map[i][j+1]) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
