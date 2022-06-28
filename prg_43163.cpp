#include <string>
#include <vector>
#include <iostream>

using namespace std;

string b, t;
vector<string> w;
vector<bool> visited;
int len=0, answer = 2147000000;

void dfs(string word, int cnt){
    if(word==t){
        if(answer>cnt) answer=cnt;
        return;
    }else{
        for(int i=0;i<t.length();i++){
            string tmpWord=word;
            string segWord=word.replace(i, 1, "");
            word=tmpWord;
            for(int j=0;j<w.size();j++){
                if(visited[j]==true) continue;
                string tmpW=w[j];
                string segW=w[j].replace(i, 1, "");
                w[j]=tmpW;
                if(word==w[j]) continue;
                if(segWord==segW){
                    visited[j]=true;
                    dfs(tmpW, cnt+1);
                    visited[j]=false;
                }
            }
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    b=begin; t=target; w.assign(words.begin(), words.end()); len=b.length();
    visited.resize(w.size(), false);

    bool check=false;
    
    for(int i=0;i<w.size();i++){
        if(t==w[i]) check=true;
    }
    
    if(check) dfs(b, 0);
    else return 0;
    
    return answer;
}
