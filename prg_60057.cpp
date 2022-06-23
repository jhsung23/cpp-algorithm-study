#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 2147000000;
    //aabbaccc
    for(int unit=1;unit<=s.size();unit++){
        int t=s.size()%unit;
        int r=s.size()-t;
        string jaturi="";
        if(t!=0){
            jaturi=s.substr(r);
        }
        string tmp=s.substr(0, s.size()-t);
        int cnt=1, idx=unit;
        string ans="", hyunstring=tmp.substr(0,unit);
        while(idx<=tmp.size()){
            if(idx==tmp.size()){
                if(cnt!=1) ans+=to_string(cnt);
                ans+=hyunstring;
                break;
            }
            string daumstring=tmp.substr(idx, unit);
            if(hyunstring==daumstring){
                cnt++;
            }else{
                if(cnt!=1) ans+=to_string(cnt);
                ans+=hyunstring;
                cnt=1;
            }
            hyunstring=daumstring;
            idx+=unit;
        }
        ans+=jaturi;
        answer=ans.size()<answer?ans.size():answer;
    }
    
    return answer;
}
