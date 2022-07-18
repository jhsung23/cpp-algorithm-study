#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> s;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0;i<phone_book.size();i++){
        for(int j=0;j<phone_book[i].length();j++){
            string str=phone_book[i].substr(0,j);
            s.insert(str);
        }
    }
    
    for(int i=0;i<phone_book.size();i++){
        auto it=s.find(phone_book[i]);
        if(it!=s.end()) return false;
    }
    
    return true;
}
