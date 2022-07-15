#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0, n2=nums.size()/2;
    set<int> s;
    
    for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);
    }
    
    if(s.size()>n2) answer=n2;
    else answer=s.size();
    return answer;
}
