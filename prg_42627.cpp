#include <string>
#include <vector>
#include <queue>

using namespace std;

// bool compare(pair<int, int> &a, pair<int, int> &b){
//     if(a.)
// }
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    queue<pair<int, int> > q;
    
    sort(jobs.begin(), jobs.end());
    q.push(make_pair(jobs[0][0], jobs[0][1]));
    int a, b;
    while(){
        a=q.front().first;
        b=q.front().second; //프로세스 끝시점
        
        for(int i=1;i<jobs.size();i++){
            if(jobs[i][0]>=a && jobs[0][1]<=b){
                pq.push(make_pair(jobs[i][0], jobs[i][1]));
            }
        }
        
        while(!pq.empty()){
            
        }
        
        
    }
    
    return answer;
}
