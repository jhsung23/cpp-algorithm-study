#include <string>
#include <vector>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    hand=toupper(hand[0]);
    int leftPos=10, rightPos=12;
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]==0) numbers[i]=11;
        
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){
            answer+="L";
            leftPos=numbers[i];
        }else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9){
            answer+="R";
            rightPos=numbers[i];
        }else{
            int leftDis=0, rightDis=0;
            
            // 왼손
            if(leftPos%3==2){
                leftDis+=abs(numbers[i]-leftPos)/3;
            }else{
                leftDis+=1;
                leftDis+=abs(numbers[i]-(leftPos+1))/3;
            }
            
            // 오른손
            if(rightPos%3==2){
                rightDis+=abs(numbers[i]-rightPos)/3;
            }else{
                rightDis+=1;
                rightDis+=abs(numbers[i]-(rightPos-1))/3;
            }
            
            // 거리 비교
            if(rightDis>leftDis) {
                answer+='L';
                leftPos=numbers[i];
            }
            else if(rightDis==leftDis) {
                answer+=hand;
                if(hand=="L") leftPos=numbers[i];
                else rightPos=numbers[i];
            }
            else {
                answer+="R";
                rightPos=numbers[i];
            }
        }
    }
    
    return answer;
}
