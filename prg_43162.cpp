#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0, start=0, cnt=0;
    
    vector<vector<int> > v(n, vector<int> (n));
    vector<bool> visited(false);
    queue<int> q;
    
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            if(computers[i][k]==1){
                v[i].push_back(k);
                v[k].push_back(i);
            }
        }
    }
    
    for(int j=0;j<n;j++){
        q.push(j);
        
        while(!q.empty()){
            int cur=q.front();
            visited[cur]=true;
            q.pop();
            for(int i=0;i<n;i++){
                if(!visited[i] && v[cur][i]==1){
                    q.push(i);
                }
            }
        }
        cnt++;
    }
    
    cout<<cnt<<endl;
    
    return answer;

}
