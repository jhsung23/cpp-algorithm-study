//
//  main.cpp
//  practice01
//
//  Created by 성지현 on 2021/11/21.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool chk(string str){
    stack<int> s;
    for(int i=0;i<str.size();i++){
        if(str[i]=='(') s.push(1);
        else{
            if(s.empty()) return false;
            else s.pop();
        }
    }

    if(s.empty()) return true;
    else return false;
}
int main(int argc, const char * argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<string> res;

    for(int i=0;i<n;i++){
        string str;
        cin>>str;

        if(chk(str)) res.push_back("YES");
        else res.push_back("NO");

    }

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<"\n";
    }
    return 0;
}
