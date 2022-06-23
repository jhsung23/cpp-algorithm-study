//
//  main.cpp
//  codeplus1-1
//
//  Created by 성지현 on 2021/11/05.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1 - >
//2 - <

int n, sign[9], ch[10]={0,};
vector<int> num;
vector<vector<int> > res;

void fun(int lv){
    if(lv==n+1){
        bool flag=true;
        for(int i=0;i<n;i++){
            if(sign[i]==1){
                if(num[i]<num[i+1]) flag=false;
            }else if(sign[i]==2){
                if(num[i]>num[i+1]) flag=false;
            }
        }
        if(flag){
            res.push_back(num);
        }
    }else{
        for(int i=0;i<10;i++){
            if(ch[i]==0){
                num[lv]=i;
                ch[i]=1;
                fun(lv+1);
                ch[i]=0;
            }
        }
    }
}
int main(int argc, const char * argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    num.resize(n+1);
    for(int i=0;i<n;i++){
        char a;
        cin>>a;
        if(a=='>') sign[i]=1;
        else if(a=='<') sign[i]=2;
    }

    fun(0);
    for(int i=0;i<n+1;i++){
        cout<<res.back()[i];
    }
    cout<<'\n';
    for(int i=0;i<n+1;i++){
        cout<<res[0][i];
    }



    return 0;
}
