#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> carIn; // 차번호, 들어온 시간
    map<string, int> minutes;
    map<string, int> result; // 차번호, 총 요금
    
    for(int i=0;i<records.size();i++){
        vector<string> tmp;
        string str;
        stringstream ss(records[i]);
        while(ss>>str) tmp.push_back(str);

        string carNo=tmp[1]; //차량 번호 parsing

        if(tmp[2]=="IN"){ //입차인 경우
            int carInTime=stoi(tmp[0].substr(0,2))*60+stoi(tmp[0].substr(3,2));
            carIn.insert(make_pair(carNo, carInTime));
            if(result.find(carNo)!=result.end()) result.insert(make_pair(carNo, 0));
            if(minutes.find(carNo)!=minutes.end()) minutes.insert(make_pair(carNo, 0));
        }else if(tmp[2]=="OUT"){ //출차인 경우
            int carOutTime=stoi(tmp[0].substr(0,2))*60+stoi(tmp[0].substr(3,2));
            int totalMinutes=carOutTime-carIn[carNo];
            minutes[carNo]+=totalMinutes;
            carIn.erase(carIn.find(carNo));
        }
    }
    
    //출차 기록이 없는 경우
    for(auto it=carIn.begin();it!=carIn.end();it++){
        int lastOutTime=23*60+59;
        int totalMin=lastOutTime-it->second;
        minutes[it->first]+=totalMin;
    }
    //요금 계산
    for(auto it=minutes.begin();it!=minutes.end();it++){
        int overtime=fees[0]-it->second;
        if(overtime<0){
            double extraCharge=ceil((double) abs(overtime)/fees[2])*fees[3];
            result[it->first]+=(int)extraCharge+fees[1];
        }else result[it->first]+=fees[1];
    }
    
    for(auto it=result.begin();it!=result.end();it++){
        answer.push_back(it->second);
    }
    
    return answer;
}
