#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> line(30000);
vector<int> dist(30000);

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>line[i];
    }

    for(int i=0;i<n-1;i++){
        cin>>dist[i];
    }

    int start=0, end=line[0]+dist[0];
    for(int i=1;i<n;i++){
        if(line[i]<=end){
            end=max(end, line[i]+dist[i]);
        }else{
            cout<<"엄마 나 전역 늦어질 것 같아"<<"\n";
            return 0;
        }
    }

    cout<<"권병장님, 중대장님이 찾으십니다"<<"\n";

    return 0;
}
