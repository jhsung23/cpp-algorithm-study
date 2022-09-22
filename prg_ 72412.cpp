#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    map<string, vector<int> > infoMap;
    vector<int> answer;
    
    for(int i=0;i<info.size();i++){
        string language, job, career, soulfood, score, tmpstring="";
        stringstream iString(info[i]);
        iString >> language >> job >> career >> soulfood >> score;
        
        vector<vector<string> > charVec(4, vector<string> (2, "-"));
        
        charVec[0][0]=language[0];
        charVec[1][0]=job[0];
        charVec[2][0]=career[0];
        charVec[3][0]=soulfood[0];
        
        for(int a=0;a<2;a++){
            string strL, strJ, strC, strS;
            strL=charVec[0][a];
            for(int b=0;b<2;b++){
                strJ=charVec[1][b];
                for(int c=0;c<2;c++){
                    strC=charVec[2][c];
                    for(int d=0;d<2;d++){
                        strS=charVec[3][d];
                        infoMap[strL+strJ+strC+strS].push_back(stoi(score));
                    }
                }
            }
        }
        infoMap[tmpstring].push_back(stoi(score));
    }
    
    for(auto it=infoMap.begin();it!=infoMap.end();it++){
        sort(it->second.begin(), it->second.end());
    }
    
    
    for(int i=0;i<query.size();i++){
        string l="", a1="", j="", a2="", c="", a3="", f="", s="", queryString="";
        stringstream qString(query[i]);
        qString >> l >> a1 >> j >> a2 >> c >> a3 >> f >> s;
        
        queryString+=l[0];
        queryString+=j[0];
        queryString+=c[0];
        queryString+=f[0];
        
        int n=lower_bound(infoMap[queryString].begin(), infoMap[queryString].end(), stoi(s))-infoMap[queryString].begin();
        answer.push_back(infoMap[queryString].size()-n);
    }
    
    return answer;
}
