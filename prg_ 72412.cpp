#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<pair<int, string> > infoString;
    vector<int> answer(query.size(), 0);
    
    for(int i=0;i<info.size();i++){
        string language, job, career, soulfood, score, tmpstring="";
        stringstream iString(info[i]);
        iString >> language >> job >> career >> soulfood >> score;
        tmpstring+=language[0];
        tmpstring+=job[0];
        tmpstring+=career[0];
        tmpstring+=soulfood[0];
        
        infoString.push_back(make_pair(stoi(score), tmpstring));
    }
    
    sort(infoString.begin(), infoString.end());
    
    for(int i=0;i<query.size();i++){
        string l="", a1="", j="", a2="", c="", a3="", f="", s="";
        stringstream queryString(query[i]);
        queryString >> l >> a1 >> j >> a2 >> c >> a3 >> f >> s;
        for(int k=0;k<infoString.size();k++){
            string str=infoString[k].second;
            if(l[0]!='-' && str[0]!=l[0]) continue;
            if(j[0]!='-' && str[1]!=j[0]) continue;
            if(c[0]!='-' && str[2]!=c[0]) continue;
            if(f[0]!='-' && str[3]!=f[0]) continue;
            if(infoString[k].first>=stoi(s)) answer[i]+=1;
            else break;
        }
    }
    return answer;
}
