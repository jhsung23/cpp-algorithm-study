#include <string>
#include <vector>
#include <iostream>

using namespace std;

int s, cnt=0, t;
vector<int> nums;

void dfs(int idx, int sum){
    if(idx>=s){
        if(sum==t) {
            cnt++;
            return;
        }
        else return;
    }else{
        dfs(idx+1, sum+nums[idx]);
        dfs(idx+1, sum-nums[idx]);
    }
}
int solution(vector<int> numbers, int target) {
    // int answer = 0;
    
    s=numbers.size();
    t=target;

    nums.assign(numbers.begin(), numbers.end());
    
    dfs(0, 0);
    
    return cnt;
}
