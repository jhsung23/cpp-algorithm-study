#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    multimap<string, string> reportMap;
    map<string, int> reportCount;
    set<string> deduplication;
    
    for(int i=0;i<report.size();i++){
        deduplication.insert(report[i]);
    }
    
    for(auto it=deduplication.begin();it!=deduplication.end();it++){
        string str=*it;
        string reportId=str.substr(0, str.find(" "));
        string reportedId=str.substr(str.find(" ")+1, str.size());
        reportMap.insert(make_pair(reportedId, reportId));
    }
    
    for(int i=0;i<id_list.size();i++){
        if(reportMap.count(id_list[i])<k) continue;
        
        for(auto it=reportMap.lower_bound(id_list[i]);it!=reportMap.upper_bound(id_list[i]);it++){
            string id=it->second;
            if(reportCount.find(id)!=reportCount.end()){
                reportCount[id]+=1;
            }else reportCount.insert(make_pair(id, 1));
        }
    }
    
    for(int i=0;i<id_list.size();i++){
        answer.push_back(reportCount[id_list[i]]);
    }
    
    
    return answer;
}
