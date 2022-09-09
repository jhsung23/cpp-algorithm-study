#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<int, vector<int> > m;
    vector<int> tmp;
    
    string str="";
    for(int i=0;i<s.size()-1;i++){
        if(isdigit(s[i])){
            str+=s[i];
            if(!isdigit(s[i+1])){
                tmp.push_back(stoi(str));
                str="";
                if(s[i+1]=='}'){
                    m.insert(make_pair(tmp.size(),tmp));
                    tmp.clear();
                }
            }
        }
    }
    
    answer.push_back((*m.begin()).second[0]);
    m.erase(1);
    for(auto it=m.begin();it!=m.end();it++){
        vector<int> tuple=(*it).second;
        for(int i=0;i<tuple.size();i++){
            if(find(answer.begin(), answer.end(), tuple[i])==answer.end()){
                answer.push_back(tuple[i]);
                break;
            }
        }
        
    }
    return answer;
}
