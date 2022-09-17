#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<char> oper;
    vector<pair<int, char> > numAndOper;
    multiset<char> ms;
    
    long long num=0;
    for(int i=0;i<expression.size();i++) {
        if(isdigit(expression[i])) num=num*10+(expression[i]-'0'); //숫자 부분 파싱
        
        if(!isdigit(expression[i])) {
            numAndOper.push_back(make_pair(num, expression[i]));
            oper.push_back(expression[i]); // 조합용 벡터
            ms.insert(expression[i]);
            num=0;
        }
    }
    numAndOper.push_back(make_pair(num, '='));
    
    sort(oper.begin(), oper.end());
    oper.erase(unique(oper.begin(), oper.end()), oper.end());
    
    do{
        vector<pair<long long, char> > tmpVec;
        multiset<char> tmpMs(ms);
        tmpVec.assign(numAndOper.begin(), numAndOper.end());
        for(int i=0;i<oper.size();i++) {
            while(tmpMs.find(oper[i])!=tmpMs.end()){
                for(int j=0;j<tmpVec.size();j++){
                    if(oper[i]!=tmpVec[j].second) continue;
                    if(tmpVec[j].second=='*') tmpVec[j+1].first=tmpVec[j].first*tmpVec[j+1].first;
                    else if(tmpVec[j].second=='+') tmpVec[j+1].first=tmpVec[j].first+tmpVec[j+1].first;
                    else if(tmpVec[j].second=='-') tmpVec[j+1].first=tmpVec[j].first-tmpVec[j+1].first;
                    tmpVec.erase(tmpVec.begin()+j);
                    tmpMs.erase(tmpMs.find(oper[i]));
                    break;
                }
            }
        }
        if(answer<abs(tmpVec[0].first)) answer=abs(tmpVec[0].first);
    }while(next_permutation(oper.begin(), oper.end()));
    
    return answer;
}
