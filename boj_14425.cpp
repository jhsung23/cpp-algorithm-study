//
//  main.cpp
//  practice02
//
//  Created by 성지현 on 2021/11/26.
//

#include <iostream>
#include <stack>
#include <set>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, cnt=0;
    cin>>n>>m;

    set<string> s;
    set<string>::iterator itr;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        s.insert(str);
    }

    for(int i=0;i<m;i++){
        string str;
        cin>>str;
        itr=s.find(str);
        if(itr!=s.end()) cnt++;
    }

    cout<<cnt<<"\n";
    return 0;
}
