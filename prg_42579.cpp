#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b){
    return a.second>b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    multiset<string> ms;
    map<string, int> m;
    multimap<int, string> m2;
    map<int, int> playandnumber;

    for(int i=0;i<genres.size();i++){
        if(m.find(genres[i])!=m.end()){
            m[genres[i]]+=plays[i];
        }else m[genres[i]]=plays[i];
        if(ms.count(genres[i])<2) ms.insert(genres[i]);
        m2.insert(pair<int, string>(plays[i], genres[i]));
        playandnumber.insert(make_pair(i, plays[i]));
    }
    
    vector<pair<string, int> > v;
    for(auto it=ms.begin();it!=ms.end();it++){
        v.push_back(make_pair(*it, m[*it]));
    }
    sort(v.begin(), v.end(), compare);

    vector<int> tmp;
    for(int i=0;i<v.size();i++){
            for(auto it=m2.rbegin();it!=m2.rend();it++){
                if(it->second==v[i].first){
                    tmp.push_back(it->first);
                    m2.erase(m2.find(it->first));
                    break;
                }
            }
    }
    
    for(int i=0;i<tmp.size();i++){
        for(auto it=playandnumber.begin();it!=playandnumber.end();it++){
            if(it->second==tmp[i]){
                answer.push_back(it->first);
                playandnumber.erase(it);
                
            }
        }
    }
    return answer;
}
