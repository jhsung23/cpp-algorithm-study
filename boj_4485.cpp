#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2147000000

struct Node{
    int x;
    int y;
    int cost;
    Node(int a, int b, int c){
        x=a;
        y=b;
        cost=c;
    }
    bool operator<(const Node &b)const{
        return cost>b.cost;
    }
};

priority_queue<Node> pq;
vector<vector<int> > map;
vector<vector<int> > dist;
vector<int> res;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    while(true){
        cin>>n;
        if(n==0) break;

        map.resize(n, vector<int>(n));
        dist.resize(n, vector<int>(n));

        fill(map.begin(), map.end(), vector<int>(n, 0));
        fill(dist.begin(), dist.end(), vector<int>(n, INF));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>map[i][j];
            }
        }

        dist[0][0]=map[0][0];
        pq.push(Node(0,0,dist[0][0]));

        while(!pq.empty()){
            int nowX=pq.top().x;
            int nowY=pq.top().y;
            int nowDis=pq.top().cost;
            pq.pop();
            if(nowDis>dist[nowX][nowY]) continue;
            for(int i=0;i<4;i++){
                int nextX=nowX+dx[i];
                int nextY=nowY+dy[i];
                if(nextX>=0 && nextX<=n-1 && nextY>=0 && nextY<=n-1){
                    int nextDist=nowDis+map[nextX][nextY];
                    if(dist[nextX][nextY]>nextDist){
                        dist[nextX][nextY]=nextDist;
                        pq.push(Node(nextX, nextY, nextDist));
                    }
                }
            }
        }
        res.push_back(dist[n-1][n-1]);    }

    for(int i=0;i<res.size();i++){
        cout<<"Problem "<<i+1<<": "<<res[i]<<"\n";
    }

}
