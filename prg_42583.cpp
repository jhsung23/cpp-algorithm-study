#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sec=1;
    queue<int> q;
    deque<pair<int, int> > bridge;
    
    for(int i=0;i<truck_weights.size();i++){
        q.push(truck_weights[i]);
    }
    
    int onBridgeWeight=q.front();
    bridge.push_back(make_pair(q.front(),1));
    q.pop();
    
    while(!bridge.empty() || !q.empty()){
        sec++;
        for(auto it=bridge.begin();it!=bridge.end();it++) {
            it->second+=1;
            cout<<it->first<<" ";
        }
        cout<<endl;
        if(bridge.front().second==bridge_length){
            onBridgeWeight-=bridge.front().first;
            bridge.pop_front();
            // q.pop();
        }
        if(onBridgeWeight+q.front()<=weight){
            if(bridge.size()>bridge_length) continue;
            bridge.push_back(make_pair(q.front(), 0));
            onBridgeWeight+=q.front();
            q.pop();
        }
    }
    return sec;
}
