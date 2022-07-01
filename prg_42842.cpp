#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> divisor;
    
    for(int i=1;i<=yellow;i++){
        if(yellow%i==0) divisor.push_back(i);
    }
    
    for(int i=0;i<divisor.size();i++){
        int garo=divisor[i];
        int sero=divisor[divisor.size()-1-i];
        
        int predBrown=(garo+2)*2+(sero*2);
        if(garo+2<sero+2) continue;
        if(predBrown==brown) return {garo+2, sero+2};
    }
    
    return answer;
}
