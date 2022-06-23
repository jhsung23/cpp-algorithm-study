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

int n, d; //n(<=12): 지름길의 개수, d(<=10000): 고속도로의 길이
vector<pair<int, int> > road[10001];
vector<int> dist(10001);

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>d;

    for(int i=0;i<d+1;i++){
        dist[i]=i;
    }

    for(int i=0;i<n;i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(c>=b-a) continue;
        if(b>d) continue;
        road[b].push_back(make_pair(a,c));
    }

    for(int i=1;i<=d;i++){
        if(road[i].size()==0) dist[i]=dist[i-1]+1;
        else{
            for(auto next:road[i]){
                dist[i]=min({dist[i], dist[i-1]+1, dist[next.first]+next.second});
            }
        }
    }
    cout<<dist[d];

    return 0;
}
