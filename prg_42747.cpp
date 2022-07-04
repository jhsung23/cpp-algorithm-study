#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    vector<int> v(citations[citations.size()-1]+1, 0);
    for(int i=0;i<citations.size();i++){
        for(int j=1;j<=citations[i];j++){
            v[j]++;
        }
    }
    
    for(int i=0;i<v.size();i++){
        if(i<=v[i]) answer= (answer<i) ? i : answer;
    }
    return answer;
}
