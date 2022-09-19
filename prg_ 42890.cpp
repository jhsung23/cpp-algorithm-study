#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<int> index(relation[0].size(), 0);
    set<vector<int> > uniq;
    
    for(int i=0;i<relation[0].size();i++){
        index.push_back(1);
        index.erase(index.begin());
        
        do{
            set<vector<string> > s;
            for(int k=0;k<relation.size();k++){
                vector<string> tmp;
                for(int j=0;j<index.size();j++){
                    if(index[j]==1) tmp.push_back(relation[k][j]);
                }
                s.insert(tmp);
            }
            if(s.size()==relation.size()) uniq.insert(index);
        }while(next_permutation(index.begin(), index.end()));
    }
    
    for(auto it=uniq.begin();it!=uniq.end();it++){
        vector<int> target;
        target.assign(it->begin(), it->end());

        auto it2=uniq.begin();
        while(it2!=uniq.end()){
            vector<int> compare, result;
            compare.assign(it2->begin(), it2->end());

            if(target==compare) {
                it2++;
                continue;
            }
            
            for(int i=0;i<relation[0].size();i++){
                result.push_back(target[i]&compare[i]);
            }
            
            if(uniq.find(result)!=uniq.end()) {
                if(compare!=result) uniq.erase(uniq.find(compare));
                if(target!=result) uniq.erase(uniq.find(target));
                it2=uniq.begin();
            }else it2++;
        }
    }
    
    return uniq.size();
}
