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
	freopen("input.txt", "rt", stdin);
	vector<vector<int> > num(9, vector<int> (9));
	vector<double> avg(9);
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>num[i][j];
			avg[i]+=num[i][j];
		}
		avg[i]/=9;
		avg[i]=round(avg[i]);
	}

	for(int i=0;i<9;i++){
		int tmp, dif=100, idx;
		cout<<avg[i]<<" ";
		for(int j=0;j<9;j++){
			tmp=abs(avg[i]-num[i][j]);
			if(tmp<dif){
				dif=tmp;
				idx=j;
			} else if(tmp==dif){
				if(num[i][j]>num[i][idx]) idx=j;
			}
		}
		cout<<num[i][idx]<<endl;
	}


	return 0;
}
