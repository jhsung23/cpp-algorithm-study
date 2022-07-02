#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end());
    
    do{
        string tmpstring="";
        for(int i=0;i<numbers.size();i++){
            tmpstring+=to_string(numbers[i]);
        }
        if(answer<tmpstring) {
            answer=tmpstring;
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    return answer;
}
