//
//  main.cpp
//  practice01
//
//  Created by 성지현 on 2021/11/21.
//

#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    int n,m;
    cin>>n>>m;

    multiset<string> ms;
    set<string> s;
    set<string>::iterator iter;
    string str;

    for(int i=0;i<n;i++){
        cin>>str;
        s.insert(str);
        ms.insert(str);
    }
    for(int i=0;i<m;i++){
        cin>>str;
        s.insert(str);
        ms.insert(str);
    }
    
    vector<string> res;
    int cnt=0;
    for(iter=s.begin();iter!=s.end();iter++){
        if(ms.count(*iter)==2){
            cnt+=1;
            res.push_back(*iter);
        }
    }

    sort(res.begin(), res.end());
    cout<<cnt<<"\n";
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<"\n";
    }


    return 0;
}
