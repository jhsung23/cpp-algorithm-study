#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5, 1);
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    for(int i=0;i<5;i++){
        vector<vector<int> > room(5, vector<int> (5, 0));
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(places[i][j][k]=='P'){
                    // room[j][k]=0;
                    for(int p=0;p<4;p++){
                        if((j+dx[p])>=0 && (j+dx[p])<5 &&
                           (k+dy[p])>=0 && (k+dy[p])<5){
                            room[j+dx[p]][k+dy[p]]+=1;
                        }
                    }
                }
            }
        }
        
        
        for(int a=0;a<5;a++){
            for(int b=0;b<5;b++){
                if(room[a][b]>=1 && places[i][a][b]=='P'){
                    answer[i]=0;
                    break;
                }
                if(room[a][b]>1 && places[i][a][b]=='O'){
                    answer[i]=0;
                    break;
                }
            }
        }
    }

    return answer;
}
