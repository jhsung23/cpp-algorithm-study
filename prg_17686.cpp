#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct File {
    string head;
    string number;
    string tail;
};
bool cmp(const File &a, const File &b){
    string tmpA="", tmpB="";
    for(int i=0;i<a.head.size();i++){
        tmpA+=tolower(a.head[i]);
    }
    for(int i=0;i<b.head.size();i++){
        tmpB+=tolower(b.head[i]);
    }
    if(tmpA < tmpB) return true;
    else if(tmpA==tmpB){
        if(stoi(a.number)<stoi(b.number)) return true;
    }
    return false;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> folder;
    
    //head, number, tail로 나누기
    for(int i=0;i<files.size();i++){
        File tmpfile;
        string h="", n="", t="";
        bool flag1=true; //head로 분류되는 동안 true, head가 끝나면 false
        bool flag2=true; //number로 분류되는 동안 true, number가 끝나면 false
        for(int k=0;k<files[i].size();k++){
                        //head에 들어갈 차례이고, 숫자가 아닌 경우라면 h에 넣음
            if(flag1 && !isdigit(files[i][k])) h+=files[i][k];
                        //number에 들어갈 차례이고, 숫자이면 n에 넣는데,
                        //number는 최대 다섯 글자이므로 문자열 길이가 5미만일때 가능
            else if(flag2 && isdigit(files[i][k]) && n.size()<5) {
                n+=files[i][k];
                flag1=false; //여기 들어왔다는건 앞으로 head에 들어갈 일이 없다는 것
                        //head와 number에 들어가고 나머지(tail에 들어갈 차례)
            }else{
                flag2=false; //이제 number에 들어갈 일 없음
                t+=files[i][k];
            }
        }
        tmpfile.head=h;
        tmpfile.number=n;
        tmpfile.tail=t;
        folder.push_back(tmpfile);
    }
    
    //정렬
    stable_sort(folder.begin(), folder.end(), cmp);
    for(int i=0;i<folder.size();i++){
        string fullname;
        fullname=folder[i].head+folder[i].number+folder[i].tail;
        answer.push_back(fullname);
    }
    
    
    return answer;
}
