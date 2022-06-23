#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2147000000

struct Node {
    int node;
    int distance;
    Node(int a, int b){
        node=a;
        distance=b;
    }
    bool operator<(const Node &b)const{
        return distance>b.distance;
    }
};
vector<int> way[1001];
vector<int> dist(1001, INF);
priority_queue<Node> pq;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int start, end, n, m;
    cin>>start>>end;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int from, to;
        cin>>from>>to;
        way[from].push_back(to);
        way[to].push_back(from);
    }

    dist[start]=0;
    pq.push(Node(start, 0));
    while(!pq.empty()){
        int now=pq.top().node;
        int nowdist=pq.top().distance;
        pq.pop();
        if(nowdist>dist[now]) continue;
        for(int i=0;i<way[now].size();i++) {
            int next=way[now][i];
            int nextdist=nowdist+1;
            if(dist[next]>nextdist){
                dist[next]=nextdist;
                pq.push(Node(next, nextdist));
            }
        }
    }

    if(dist[end]==INF) cout<<-1<<"\n";
    else cout<<dist[end]<<"\n";

    return 0;
}
