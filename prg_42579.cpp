#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<int> tmp;
    multiset<string> ms;
    map<int, string> m;
    map<int, int> musicNumber;
    
    for(int i=0;i<genres.size();i++){
        if(ms.count(genres[i])<2) ms.insert(genres[i]);
        m.insert(make_pair(plays[i], genres[i]));
        musicNumber.insert(make_pair(plays[i], i));
    }
    
    while(!ms.empty()){
        string curGenre=m.rbegin()->second;
        int curPlay=m.rbegin()->first;
        
        //1번
        if(ms.count(curGenre)<0) continue;
        
        tmp.push_back(curPlay);
        m.erase(m.find(curPlay));
        ms.erase(ms.find(curGenre));
        
        //2번
        if(ms.count(curGenre)<0) continue;
        
        for(auto it=m.rbegin();it!=m.rend();it++){
            if(it->second==curGenre){
                tmp.push_back(it->first);
                m.erase(m.find(it->first));
                ms.erase(ms.find(curGenre));
            }
        }
    }
    
    for(int i=0;i<tmp.size();i++){
        answer.push_back(musicNumber[tmp[i]]);
    }
    
    for(int i=0;i<tmp.size();i++){
        cout<<tmp[i]<<" ";
    }
    return answer;
}
