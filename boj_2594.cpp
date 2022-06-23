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

    int n;
    cin>>n;

    vector<pair<int, int> > sch(n);
    vector<pair<int, int> > rest;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        sch[i]=make_pair(a,b);
    }

    sort(sch.begin(), sch.end());
    rest.push_back(make_pair(1000, sch[0].first));

    int start=sch[0].first, end=sch[0].second;
    for(int i=1;i<n;i++){
        if(sch[i].first<=end) end=max(end,sch[i].second);
        else{
            rest.push_back(make_pair(end, sch[i].first));
            start=sch[i].first;
            end=sch[i].second;
        }
    }
    rest.push_back(make_pair(end, 2200));
    int res=0;
 
    for(int i=0;i<rest.size();i++){
        if(rest[i].first==rest[i].second) continue;
        int restTime=0;
        int sHour=rest[i].first/100, sMin=rest[i].first%100;
        int eHour=rest[i].second/100, eMin=rest[i].second%100;
        if(sMin>eMin){
            restTime+=(eHour-sHour-1)*60;
            restTime+=(eMin-sMin+60);
        }else{
            restTime+=(eHour-sHour)*60;
            restTime+=eMin-sMin;
        }
        if(rest[i].first==1000 || rest[i].second==2200) restTime-=10;
        else restTime-=20;
        res=max(res,restTime);
    }

    cout<<res<<"\n";


    return 0;
}
