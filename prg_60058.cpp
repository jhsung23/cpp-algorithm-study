#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool isRightString(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        if(str[i]=='(') s.push('(');
        else if (str[i]==')') {
            if(!s.empty()) s.pop();
            else return false;
        }
    }
    
    if(s.empty()) return true;
    else return false;
}
string solution(string p) {
    string answer = "";
    
    int leftCnt=0, rightCnt=0;
    string u,v;
    
    //1
    if(p=="") return answer;
    
    //2
    for(int i=0;i<p.size();i++){
        if(p[i]=='(') leftCnt++;
        else if(p[i]==')') rightCnt++;
        
        if(leftCnt==rightCnt) {
            u=p.substr(0,i+1);
            v=p.substr(i+1);
            break;
        }
    }
    
    //3
    if(isRightString(u)){
        v=solution(v);
        answer=u+v;
        return answer;
    }else{
        string tmp="(";
        tmp+=solution(v);
        tmp+=")";
        u.pop_back();
        u=u.substr(1);
        for(int k=0;k<u.size();k++){
            if(u[k]=='(') tmp+=')';
            else tmp+='(';
        }
        return tmp;
    }
    
    
    return answer;
}
