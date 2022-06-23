//
//  main.cpp
//  practice02
//
//  Created by 성지현 on 2021/11/26.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    stack<char> stac;
    queue<char> q;
    getline(cin, s, '\n');

    bool flag=false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='<'){
            //cout<<"1";
            while(!stac.empty()){
                cout<<stac.top();
                stac.pop();
            }
            q.push('<');
            flag=true;
        }else if(s[i]=='>'){
            //cout<<"3";
            flag=false;
            q.push('>');
            while(!q.empty()){
                //cout<<"4";
                cout<<q.front();
                q.pop();
            }
        }else if(flag){
            //cout<<"2";
            q.push(s[i]);
        }else if(isblank(s[i])){
            while(!stac.empty()){
                cout<<stac.top();
                stac.pop();
            }
            cout<<" ";
        }else{
            stac.push(s[i]);
        }
    }

    while(!stac.empty()){
        cout<<stac.top();
        stac.pop();
    }
    cout<<endl;

    return 0;
}
