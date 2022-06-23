#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    //캐시 사이즈는 최대 30, 도시는 최대 100,000개
    int answer = 0;
    deque<string> dq;
    set<string> s;
    
    if(cacheSize==0) return cities.size()*5;
    
    for(int i=0;i<cities.size();i++){
        string city="";
        //소문자로 변환
        for(int k=0;k<cities[i].size();k++){
            city+=tolower(cities[i][k]);
        }
        //city가 캐시에 있다면
        if(s.find(city)!=s.end()){
            for(deque<string>::iterator it=dq.begin();it!=dq.end();++it){
                if(*it==city){
                    dq.erase(it);
                    dq.push_back(city);
                    break;
                }
            }
            answer+=1;
        }else{ //없다면
            if(s.size()>=cacheSize){ //캐시가 꽉찼다면 (비워줘야됨)
                if(s.find(dq.front())!=s.end()){ //지울 항목 캐시에서 찾음
                    s.erase(s.find(dq.front()));
                    dq.pop_front();
                }
            }//캐시에 공간이 있다면
            dq.push_back(city);
            s.insert(city);
            answer+=5;
        }
        // for(deque<string>::iterator it=dq.begin();it!=dq.end();++it){
        //     cout<<*it<<" ";
        // }
        // cout<<endl;
    }
    
    return answer;
}
