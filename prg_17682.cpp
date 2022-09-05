#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score;
    string tmpString="";
    
    for(int i=0;i<dartResult.size();i++){
        if(isdigit(dartResult[i])) {
            tmpString+=dartResult[i];
        }
        else{
            if(tmpString.size()>0) score.push_back(stoi(tmpString));
            tmpString="";

            int idx=score.size()-1;
            
            if(dartResult[i]=='S'){
                score[idx]=pow(score[idx],1);
            }else if(dartResult[i]=='D'){
                score[idx]=pow(score[idx],2);
            }else if(dartResult[i]=='T'){
                score[idx]=pow(score[idx],3);
            }else if(dartResult[i]=='*'){
                if(idx>0){
                    score[idx-1]*=2;
                }
                score[idx]*=2;
            }else if(dartResult[i]=='#'){
                score[idx]*=-1;
            }
        }
    }
    
    for(int i=0;i<score.size();i++){
        answer+=score[i];
    }
    return answer;
}
