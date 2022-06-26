#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0, start=0;
    
    vector<int> v[n];
    vector<bool> visited(n, false);
    queue<int> q;
    
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            if(i!=k && computers[i][k]==1){
                v[i].push_back(k);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            q.push(i);
        
            while(!q.empty()){
                int cur=q.front();
                visited[cur]=true;
                q.pop();
                for(int j=0;j<v[cur].size();j++){
                    if(!visited[v[cur][j]]){
                        q.push(v[cur][j]);
                    }
                }
            }
            answer++;
        }
    }
    
    return answer;

}
