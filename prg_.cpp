#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int> > q;
    vector<int> print;
    
    for(int i=0;i<priorities.size();i++){
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        int mostPrio=pq.top();
        pair<int, int> tmp=q.front();
        q.pop();
        if(tmp.second>=mostPrio){
            print.push_back(tmp.first);
            pq.pop();
        }else q.push(tmp);
    }
    for(int i=0;i<print.size();i++){
        if(print[i]==location) return i+1;
    }
    
    return answer;
}
