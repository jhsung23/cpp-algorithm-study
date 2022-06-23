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
int n, m, start, destination;
vector<pair<int, int> > graph[1001];
priority_queue<Node> pq;
vector<int> dist(20001, 2147000000);
vector<int> visited(20001, 0);

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;

    for(int i=0;i<m;i++){
        int from, to, cost;
        cin>>from>>to>>cost;
        graph[from].push_back(make_pair(to, cost));
    }
    cin>>start>>destination;

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

    cout<<dist[destination]<<"\n";
    return 0;
}
