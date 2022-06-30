#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
vector<int> numbers;
set<int> numset;

bool isPrime(int num){
    if(num==0 || num==1) return false;
    if(num==2) return true;
    for(int i=2;i<num;i++){
        if(num%i==0) return false;
    }
    return true;
}
int solution(string nums) {
    int answer = 0;
    
    for(int i=1;i<=nums.length();i++){
        vector<bool> v(nums.length()-i, false);
        v.insert(v.end(), i, true);
        
        do{
            string tmp="";
            vector<char> tmpvector;
            for(int j=0;j<nums.length();j++){
                if(v[j]) {
                    tmp+=nums[j];
                    tmpvector.push_back(nums[j]);
                }
            }
            sort(tmpvector.begin(), tmpvector.end());
            do{
                string str="";
                for(int i=0;i<tmpvector.size();i++){
                    str+=tmpvector[i];
                }
                numset.insert(stoi(str));
            }while(next_permutation(tmpvector.begin(), tmpvector.end()));
        }while(next_permutation(v.begin(), v.end()));
    }
    
    for(auto it=numset.begin();it!=numset.end();++it){
        if(isPrime(*it)) answer++;
    }
    return answer;
}
