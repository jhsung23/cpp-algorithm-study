#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string> > io;
    unordered_map<string, string> nickname; //hash_map
    
    for(int i=0;i<record.size();i++){
        string str=record[i];
        string inout, uid, nick;
        istringstream ss(str);
        ss>>inout;
        ss>>uid;
        ss>>nick;
        io.push_back(make_pair(inout, uid));
        if(inout!="Leave") nickname[uid]=nick; //별표*****
    }

    for(int i=0;i<io.size();i++){
        string nick;
        unordered_map<string, string>::iterator itr=nickname.find(io[i].second);
        if(itr!=nickname.end()) nick=itr->second;
        
        if(io[i].first=="Enter"){
            string ans=nick+"님이 들어왔습니다.";
            answer.push_back(ans);
        }else if(io[i].first=="Leave"){
            string ans=nick+"님이 나갔습니다.";
            answer.push_back(ans);
        }
    }

    return answer;
}
