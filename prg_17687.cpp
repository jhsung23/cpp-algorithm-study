#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    //n진법, t개 구하기, m명 참가, 튜브는 p번째 순서
    stack<char> tmpStack;
    vector<char> ansVec;

    ansVec.push_back('0');
    ansVec.push_back('1');

    int num=2;
    while(ansVec.size()<=m*t){
        int start=num;
        while(start>0){
            if(start==1){
                tmpStack.push('1');
                break;
            }
            char tmpChar;
            if(start%n>=10) tmpChar='A'+(start%n-10);
            else tmpChar=(char)(start%n+48);
            tmpStack.push(tmpChar);
            start/=n;
        }
        while(!tmpStack.empty()){
            ansVec.push_back(tmpStack.top());
            tmpStack.pop();
        }
        num+=1;
    }
    
    for(int i=0;i<ansVec.size();i++){
        //cout<<ansVec[i];
        if(answer.size()==t) break;
        if(i%m==p-1) answer+=ansVec[i];
    }
    
    return answer;
}
