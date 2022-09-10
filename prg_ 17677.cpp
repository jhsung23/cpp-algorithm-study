#include <string>
#include <set>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    multiset<string> ms1, ms2, unionSet, interSet;

    //str1
    string str="";
    for(int i=0;i<str1.size()-1;i++){
        if(isalpha(str1[i]) && isalpha(str1[i+1])) {
            str+=tolower(str1[i]);
            str+=tolower(str1[i+1]);
        }
        
        if(str.size()==2){
            ms1.insert(str);
            str="";
        }
    }
    
    //str2
    str="";
    for(int i=0;i<str2.size()-1;i++){
        if(isalpha(str2[i]) && isalpha(str2[i+1])) {
            str+=tolower(str2[i]);
            str+=tolower(str2[i+1]);
        }
        
        if(str.size()==2){
            ms2.insert(str);
            str="";
        }
    }

    if(ms1.size()==0 && ms2.size()==0) return 65536;
    
    int sizediff=abs(int(ms1.size()-ms2.size()));
    while(ms1.size()!=ms2.size()){
        ms1.size()>ms2.size() ? ms2.insert("_") : ms1.insert("_");
    } // set size 맞추는 용...
    
    set_union(ms1.begin(), ms1.end(), ms2.begin(), ms2.end(), inserter(unionSet, unionSet.begin()));
    set_intersection(ms1.begin(), ms1.end(), ms2.begin(), ms2.end(), inserter(interSet, interSet.begin()));

    double d=(double) interSet.size() /(double) (unionSet.size()-sizediff)*65536.0;
    answer=d;

    
    return answer;
}
