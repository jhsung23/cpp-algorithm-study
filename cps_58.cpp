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
void midleftright(int v){
	if(v>7) return;
	else{
		cout<<v<<" ";
		midleftright(v*2);
		midleftright(v*2+1);
	}
}
void leftmidright(int v){
	if(v>7) return;
	else{
		leftmidright(v*2);
		cout<<v<<" ";
		leftmidright(v*2+1);
	}
}
void leftrightmid(int v){
	if(v>7) return;
	else{
		leftrightmid(v*2);
		leftrightmid(v*2+1);
		cout<<v<<" ";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);

	cout<<"전위순회 출력: ";
	midleftright(1);
	cout<<endl;
	cout<<"중위순회 출력: ";
	leftmidright(1);
	cout<<endl;
	cout<<"후위순회 출력: ";
	leftrightmid(1);
	cout<<endl;

	return 0;
}
