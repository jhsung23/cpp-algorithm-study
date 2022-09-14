#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
//높이 m 가로 n
int solution(int m, int n, vector<string> board) {
    int answer = 0; //지워지는 블록의 개수
    vector<vector<string>> newBoard(n, vector<string> (m));

    //2차원 vector 회전
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            newBoard[i][j]=board[m-j-1][i];
        }
    }
    
    while(true){
        set<pair<int, int> > hitBlocks;
        //현재위치에서 오른쪽, 아래, 오른쪽아래대각선 같은지 검사
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                string target=newBoard[i][j];
                if(target=="X") continue;
                if(target==newBoard[i][j+1] && target==newBoard[i+1][j] && target==newBoard[i+1][j+1]){
                    //모두 같은 경우 hitBlocks에 넣기
                    hitBlocks.insert(make_pair(i, j));
                    hitBlocks.insert(make_pair(i+1, j));
                    hitBlocks.insert(make_pair(i, j+1));
                    hitBlocks.insert(make_pair(i+1, j+1));
                }
            }
        }

        if(hitBlocks.size()==0) break; //종료 조건
        else answer+=hitBlocks.size();
        
        for(auto it=hitBlocks.begin();it!=hitBlocks.end();it++){
            int x=it->first, y=it->second;
            newBoard[x][y]="_";
        }

        for(int i=0;i<n;i++){
            while(true){
                auto it=find(newBoard[i].begin(), newBoard[i].end(), "_");
                if(it==newBoard[i].end()) break;
                if(newBoard[i].size()==1) newBoard[i][0]="X";
                else newBoard[i].erase(it);
            }
        }

        for(int i=0;i<n;i++){
            int size=newBoard[i].size();
            while(size!=m){
                newBoard[i].push_back("X");
                size++;
            }
        }

        hitBlocks.clear();
    }
    return answer;
}
