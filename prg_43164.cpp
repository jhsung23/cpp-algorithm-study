#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<string> > t; //전역 tickets
vector<vector<string> > answer; //tmp들을 담은 배열
vector<string> tmp; //dfs 임시 답
vector<vector<bool> > visited;

void dfs(string city, int degree){
    if(degree==t.size()+1){
        answer.push_back(tmp);
    }else{
        for(int i=0;i<t.size();i++){
            if(t[i][0]!=city) continue;
            if(!visited[i][1]){
                visited[i][1]=true;
                tmp.push_back(t[i][1]);
                dfs(t[i][1], degree+1);
                visited[i][1]=false;
                tmp.pop_back();
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    t.assign(tickets.begin(), tickets.end());
    visited.resize(t.size(), vector<bool>(2, false));
    
    tmp.push_back("ICN");
    dfs("ICN", 1);

    sort(answer.begin(), answer.end());
    return answer[0];
}
