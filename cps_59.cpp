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
int n, ch[11];
void DFS(int lv){
	if(lv==n+1){
		for(int i=1;i<=n;i++){
			if(ch[i]==1) cout<<i<<" ";
		}
		cout<<endl;
	}else{
		ch[lv]=1;
		DFS(lv+1);
		ch[lv]=0;
		DFS(lv+1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin>>n;
	DFS(1);

	return 0;
}
