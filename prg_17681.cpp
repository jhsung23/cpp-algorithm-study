#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0;i<n;i++){
        int a=arr1[i]|arr2[i];
        string tmpString="";
        while(a>0){
            if(a%2==0) tmpString+=" ";
            else tmpString+='#';
            a/=2;
        }
        
        while(tmpString.size()<n){
            tmpString+=" ";
        }
        reverse(tmpString.begin(), tmpString.end());
        answer.push_back(tmpString);
    }
    return answer;
}
