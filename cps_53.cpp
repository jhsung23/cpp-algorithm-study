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
int stackk[100], top=-1;
void push(int n){
	stackk[++top]=n;
}
int pop(){
	return stackk[top--];
}
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	//스택 stl 사용하지 않고 구현
	int n, k;
	char str[20]="0123456789ABCDEF"; //pop해온 값을 이 배열의 인덱스로 사용하여 출력(16진수 때문에)
	cin>>n>>k;

	while(n!=0){
		push(n%k);
		n/=k;
	}
	while(top!=-1){
		cout<<str[pop()];
	}
	return 0;
}
