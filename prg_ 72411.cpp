#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    multiset<string> ms;
    set<string> s;
    
    for(int i=0;i<orders.size();i++){ //orders안에 있는 문자열 하나씩 볼것
        vector<char> order; //orders의 원소 문자열의 문자 하나하나를 담은 char 배열
        for(int j=0;j<orders[i].size();j++){ //문자열의 문자를 order에 담아
            order.push_back(orders[i][j]);
        }
        
        sort(order.begin(), order.end());

        for(int j=0;j<course.size();j++){
            if(order.size()<course[j]) break;
            vector<int> partition(order.size(), 0);
            
            for(int k=0;k<course[j];k++) partition[k]=1;
            sort(partition.begin(), partition.end());
            do{
                string orderCombination="";
                for(int k=0;k<partition.size();k++){
                    if(partition[k]==1) orderCombination+=order[k];
                }
                
                if(s.find(orderCombination)==s.end()) s.insert(orderCombination);
                ms.insert(orderCombination);
                
            }while(next_permutation(partition.begin(), partition.end()));
        }
    }
    
    vector<vector<pair<int, string> > > countAndString(11); //idx는 스트링 길이
    
    for(auto it=s.begin();it!=s.end();it++){
        //ms에서 카운트 개수 구해서 카운트랑 스트링 페어로 벡터 인덱스(스트링 길이)에 넣기
        int count=ms.count(*it);
        string str=*it;
        int size=str.size();
        if(count>=2) countAndString[size].push_back(make_pair(count, str));
    }
    
    for(int i=0;i<countAndString.size();i++){
        if(countAndString[i].size()==0) continue;
        if(countAndString[i].size()==1) {
            answer.push_back(countAndString[i][0].second);
            continue;
        }
        
        sort(countAndString[i].rbegin(), countAndString[i].rend());
        int c=countAndString[i][0].first;
        for(int j=0;j<countAndString[i].size();j++){
            if(countAndString[i][j].first==c){
                answer.push_back(countAndString[i][j].second);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
