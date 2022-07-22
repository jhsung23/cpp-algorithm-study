#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<int> v;
    
    for(int i=0;i<dungeons.size();i++){
        v.push_back(i);
    }
    
    do{
        int curK=k;
        int count=0;
        for(int i=0;i<v.size();i++){
            if(curK>=dungeons[v[i]][0]){
                count++;
                curK-=dungeons[v[i]][1];
            }
        }
        answer=(count>answer) ? count : answer;
    }while(next_permutation(v.begin(), v.end()));
    
    return answer;
}
