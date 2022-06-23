//
//  main.cpp
//  recota6
//
//  Created by 성지현 on 2021/11/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, res=0;
    vector<pair<int, int> > line;
    cin>>n;

    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        line.push_back(make_pair(a, b));
    }

    int start=line[0].first, end=line[0].second;
    for(int i=1;i<n;i++){
        if(line[i].first<=end) end=max(end, line[i].second);
        else{
            res+=end-start;
            start=line[i].first;
            end=line[i].second;
        }
    }
    res+=end-start;

    cout<<res<<"\n";

    return 0;
}
