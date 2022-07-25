#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 2147000000;
    
    for(int i=0;i<wires.size();i++){
        vector<vector<int> > connect(n+1);
        vector<bool> visited(n+1, false);
        queue<int> q;
        for(int j=0;j<wires.size();j++){
            if(i==j) continue;
            connect[wires[j][0]].push_back(wires[j][1]);
            connect[wires[j][1]].push_back(wires[j][0]);
        }
        
        int count=0;
        q.push(1);
        while(!q.empty()){
            int curNode=q.front();
            q.pop();
            if(visited[curNode]) continue;
            else {
                visited[curNode]=true;
                count+=1;
            }
            
            for(int k=0;k<connect[curNode].size();k++){
                q.push(connect[curNode][k]);
            }
        }
        
        int graph1=count;
        int graph2=n-count;
        int tmpAns=abs(graph1-graph2);
        answer=tmpAns<answer? tmpAns:answer;
    }
    return answer;
}
