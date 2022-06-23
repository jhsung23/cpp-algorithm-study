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
void recur(int n){
	if(n==0) return;
	else{
		recur(n-1);
		cout<<n<<" ";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int num;
	cin>>num;
	recur(num);
	return 0;
}
