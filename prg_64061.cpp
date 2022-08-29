#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stack;
    
    for(int i=0;i<moves.size();i++){
        for(int j=0;j<board.size();j++){
            int pos=board[j][moves[i]-1];
            if(pos==0) continue;
            
            if(stack.size()>0 && stack.top()==pos) {
                answer+=2;
                stack.pop();
            }
            else stack.push(pos);
            board[j][moves[i]-1]=0;
            
            break;
        }
    }
    
    return answer;
}
