#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i=0;i<progresses.size();i++){
        q.push(i);
    }
    int curIdx=0;
    
    while(!q.empty()){
        int count=0;
        for(int i=0;i<progresses.size();i++){
            progresses[i]+=speeds[i];
        }
        
        while(curIdx<progresses.size() && progresses[curIdx]>=100){
            count+=1;
            q.pop();
            curIdx++;
        }
        
        if(count!=0) answer.push_back(count);
    }
    return answer;
}
