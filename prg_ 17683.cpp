#include <string>
#include <vector>
using namespace std;

int calTotalMM(int sHour, int sMin, int eHour, int eMin){
    // if(eHour==0) eHour=24;
    if(sMin>eMin){
        int totalHH=eHour-sHour-1;
        int totalMM=60-sMin+eMin;
        return totalHH*60+totalMM;
    }else if(sMin<eMin){
        int totalHH=eHour-sHour;
        int totalMM=eMin-sMin;
        return totalHH*60+totalMM;
    }else return (eHour-sHour)*60;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    pair<string, int> tmpAns=make_pair("(None)", 0);
    
    for(int i=0;i<musicinfos.size();i++){
        int startHH=stoi(musicinfos[i].substr(0,2));
        int startMM=stoi(musicinfos[i].substr(3,2));
        
        int endHH=stoi(musicinfos[i].substr(6,2));
        int endMM=stoi(musicinfos[i].substr(9,2));
        
        //총 재생 시간
        int totalMM=calTotalMM(startHH, startMM, endHH, endMM);
        
        //음악 제목 문자열 구하기
        string musicTitle=musicinfos[i].substr(12, musicinfos[i].find(',', 12)-12);
        //음악 코드 문자열 구하기
        string musicCode=musicinfos[i].substr(musicinfos[i].find(',',12)+1, musicinfos[i].length()-musicinfos[i].find(',',12));
        
        //음악 문자열 속 코드 개수 구하기
        int mCodeCount=0, musicCodeCount=0;
        for(int j=0;j<musicCode.length();j++) if(isalpha(musicCode[j])) musicCodeCount+=1;
        
        //재생된 총 코드 구하기
        string fullCode="";
        //전체 재생시간보다 코드가 길다면 재생시간만큼만 풀코드로 잡기(잘라내기)
        if(totalMM<musicCodeCount){
            int count=0, j=0;
            while(count<totalMM){
                if(isalpha(musicCode[j]) && isalpha(musicCode[j+1])) {
                    fullCode+=musicCode[j];
                    count++;
                }
                else if(isalpha(musicCode[j]) && !isalpha(musicCode[j+1])) {
                    fullCode+=musicCode[j];
                    fullCode+=musicCode[j+1];
                    count++;
                }
                j++;
            }
        } else { //재생시간동안 재생된 코드 전체
            for(int j=0;j<totalMM/musicCodeCount;j++) fullCode+=musicCode;
            int count=0, j=0;
            while(count<totalMM%musicCodeCount){
                if(j+1>=musicCode.length()) continue;
                if(isalpha(musicCode[j]) && isalpha(musicCode[j+1])){
                    fullCode+=musicCode[j];
                    count++;
                }else if(isalpha(musicCode[j]) && !isalpha(musicCode[j+1])){
                    fullCode+=musicCode[j];
                    fullCode+=musicCode[j+1];
                    count++;
                }
                j++;
            }
        }
        
        for(int k=0;k<fullCode.size();k++){
            if(fullCode.find(m, k)==string::npos) break;
            if(fullCode[fullCode.find(m, k)+m.size()]=='#') continue;
            if(totalMM<=tmpAns.second) continue;
            tmpAns=make_pair(musicTitle, totalMM);
            break;
        }
    }
    
    return tmpAns.first;
    
}
