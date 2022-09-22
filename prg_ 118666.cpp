#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string result = "";
    map<char, int> m={{'A', 0}, {'N', 0}, {'C', 0}, {'F', 0}, {'M', 0}, {'J', 0}, {'R', 0}, {'T', 0},};
    
    for(int i=0;i<survey.size();i++){
        if(choices[i]-4>0){
            m[survey[i][1]]+=abs(choices[i]-4);
        }else if(choices[i]-4<0){
            m[survey[i][0]]+=abs(choices[i]-4);
        }else continue;
    }
    
    if(m['R']>=m['T']) result+='R';
    else result+='T';
    
    if(m['C']>=m['F']) result+='C';
    else result+='F';
    
    if(m['J']>=m['M']) result+='J';
    else result+='M';
    
    if(m['A']>=m['N']) result+='A';
    else result+='N';
    
    return result;
}
