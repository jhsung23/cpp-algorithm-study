#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    multiset<string> ms;
    set<pair<string, int> > s;
    
    for(int i=0;i<clothes.size();i++){
        ms.insert(clothes[i][1]);
    }
    
    for(auto it=ms.begin();it!=ms.end();++it){
        s.insert(make_pair(*it, ms.count(*it)));
    }
    
    for(auto it=s.begin();it!=s.end();it++){
        answer*=(it->second)+1;
    }
    
    
    return answer-1;
}
