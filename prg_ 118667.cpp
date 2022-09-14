#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0, p1=0, p2=0;
    int q1Size=queue1.size(), q2Size=queue2.size();

    long long q1Sum=0, q2Sum=0;

    for(int i=0;i<queue1.size();i++) q1Sum+=queue1[i];
    for(int i=0;i<queue2.size();i++) q2Sum+=queue2[i];

    if((q1Sum+q2Sum)%2!=0) return -1;

    while(true){
        if(q1Sum==q2Sum) break;
        else answer++;
        
        if(q1Sum<q2Sum){
            queue1.push_back(queue2[p2]);
            q1Sum+=queue2[p2];
            q2Sum-=queue2[p2];
            queue2[p2]=0;
            p2++;
        }else{
            queue2.push_back(queue1[p1]);
            q2Sum+=queue1[p1];
            q1Sum-=queue1[p1];
            queue1[p1]=0;
            p1++;
        }
        
        if(answer>(q1Size+q2Size)*3) return -1;
    }
    
    return answer;
}
