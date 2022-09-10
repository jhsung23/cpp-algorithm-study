#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(long long n){
    if(n==1) return false;
    for(long long i=2;i<(long long)pow(n,0.5)+1;i++) if(n%i==0) return false;
    
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    vector<int> number;
    
    while(n>0){
        number.push_back(n%k);
        n/=k;
    }
    
    reverse(number.begin(), number.end());
    
    long long checkNum=0;
    for(int i=0;i<number.size();i++){
        if(number[i]!=0) checkNum=checkNum*10+number[i];

        if(i==number.size()-1 || number[i]==0){
            if(checkNum==0) continue;
            if(isPrime(checkNum)) answer+=1;
            checkNum=0;
        }
    }
    
    return answer;
}
