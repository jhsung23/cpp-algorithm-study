#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5, 1);
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                queue<pair<int, int> > q;
                vector<vector<bool> > visited(5, vector<bool> (5, false));
                vector<vector<int> > dist(5, vector<int> (5, 0));
                    
                //p가 아니라면 bfs시도 x
                if(places[i][j][k]!='P') continue;
                q.push(make_pair(j,k));
                
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    visited[x][y]=true;
                    q.pop();
                    for(int t=0;t<4;t++){
                        int nextX=x+dx[t];
                        int nextY=y+dy[t];
                        
                        if(nextX<5 && nextX>=0 && nextY<5 && nextY>=0){
                            if(!visited[nextX][nextY] &&
                               places[i][nextX][nextY]=='O'){
                                q.push(make_pair(nextX, nextY));
                                dist[nextX][nextY]=dist[x][y]+1;
                            }else if(!visited[nextX][nextY] &&
                               places[i][nextX][nextY]=='P'){
                                q.push(make_pair(nextX, nextY));
                                dist[nextX][nextY]=dist[x][y]+1;
                            }
                        }
                    }
                }
                
                for(int p=0;p<5;p++){
                    for(int q=0;q<5;q++){
                        if(places[i][p][q]=='P' &&
                           dist[p][q]!=0 && dist[p][q]<=2){
                            answer[i]=0;
                            break;
                        }
                    }
                }
                
            }
        }
    }

    return answer;
}
