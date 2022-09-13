#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<string> dic={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    vector<int> answer;
    
    int i=0, p=1;
    while(i+p<msg.size()){
        string w=msg.substr(i, p);
        string wc=msg.substr(i, p+1);
            
        auto wcIter=find(dic.begin(), dic.end(), wc);
        if(wcIter!=dic.end()) {
            p+=1;
            continue;
        }
            
        auto wIter=find(dic.begin(), dic.end(), w);
        answer.push_back(wIter-dic.begin()+1);
        dic.push_back(wc);
        i+=p;
        p=1;
    }
    
    auto lastIter=find(dic.begin(), dic.end(), msg.substr(i, p+1));
    answer.push_back(lastIter-dic.begin()+1);

    return answer;
}
