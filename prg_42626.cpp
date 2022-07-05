#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    
    while(pq.top()<K){
        if(pq.size()==1) return -1;
        
        int minScoville=pq.top();
        pq.pop();
        int secondMinScoville=pq.top();
        pq.pop();
        
        int newScoville=minScoville+secondMinScoville*2;
        pq.push(newScoville);
        answer+=1;
    }
    
    return answer;
}
