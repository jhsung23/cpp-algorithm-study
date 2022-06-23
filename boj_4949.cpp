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
    stack<char> s;
    for(int i=0;i<str.size();i++){
        if(str[i]=='(') s.push('(');
        else if(str[i]=='[') s.push('[');
        else{
            if(str[i]==')') {
                if(!s.empty() &&s.top()=='(') s.pop();
                else return false;
            }
            else if(str[i]==']') {
                if(!s.empty() && s.top()=='[') s.pop();
                else return false;
            }
        }
    }

    if(s.empty()) return true;
    else return false;
}
int main(int argc, const char * argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<string> res;
    vector<string> strvec;

    while(true){
        string str;
        getline(cin, str, '.');

        if(str.size()==1) break;

        if(chk(str)) res.push_back("yes");
        else res.push_back("no");
    }

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<"\n";
    }
    return 0;
}
