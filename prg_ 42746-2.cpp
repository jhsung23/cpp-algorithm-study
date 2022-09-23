#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return a+b<b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strings;
    
    for(int i=0;i<numbers.size();i++){
        strings.push_back(to_string(numbers[i]));
    }
    
    sort(strings.rbegin(), strings.rend(), cmp);
    
    if(strings[0]=="0") return "0";

    for(int i=0;i<strings.size();i++){
        answer+=strings[i];
    }
    return answer;
}
