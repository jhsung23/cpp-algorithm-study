#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

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
            if(s.size()==relation.size()) {uniq.insert(index); cout<<"Dd"<<endl;}
        }while(next_permutation(index.begin(), index.end()));
    }
    
    for(auto it=uniq.begin();it!=uniq.end();it++){
        vector<int> tmp;
        tmp.assign(it->begin(), it->end());
        for(int i=0;i<tmp.size();i++){
            cout<<tmp[i]<<" ";
        }
        cout<<endl;
    }
    return answer;
}
