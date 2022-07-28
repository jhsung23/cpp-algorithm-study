#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    map<char, int> m;
    char c[5]={'A','E','I','O','U'};
    int plus[5]={781, 156, 31, 6, 1};
    for(int i=0;i<5;i++){
        m.insert(make_pair(c[i], i));
    }
    
    for(int i=0;i<word.length();i++){
        answer+=1;
        answer+=(m[word[i]]*plus[i]);
    }
    return answer;
}
