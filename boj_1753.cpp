//
//  main.cpp
//  assignment5
//
//  Created by 성지현 on 2021/11/09.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
    int node;
    int weight;
    Node(int a, int b){
        node=a;
        weight=b;
    }
    bool operator<(const Node &b)const{
        return weight>b.weight;
    }
};
int v, e, start;
vector<pair<int, int> > graph[20001];
priority_queue<Node> pq;
vector<int> dist(20001, 2147000000);
vector<int> visited(20001, 0);

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>v>>e;
    cin>>start;

    for(int i=0;i<e;i++){
        int from, to, weight;
        cin>>from>>to>>weight;
        graph[from].push_back(make_pair(to, weight));
    }

    visited[start]=1;
    dist[start]=0;

    pq.push(Node(start, 0));
    while(!pq.empty()){
        int now=pq.top().node;
        int nowdist=pq.top().weight;
        pq.pop();
        if(nowdist>dist[now]) continue;
        for(auto nod:graph[now]){
            int next=nod.first;
            int nextdist=nowdist+nod.second;
            if(dist[next]>nextdist){
                dist[next]=nextdist;
                pq.push(Node(next, nextdist));
            }
        }
    }

    for(int i=1;i<=v;i++){
        if(dist[i]==2147000000) cout<<"INF"<<"\n";
        else cout<<dist[i]<<"\n";
    }
    return 0;
}
