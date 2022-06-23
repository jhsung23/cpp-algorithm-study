#include <iostream>
#include <vector>
using namespace std;

//selfnumber들 담을 배열 만들기
const int SIZE = 10000;
bool selfnumbers[SIZE + 1] = { false };

void selfnumber(int num)
{
	//selfnumber인지 검사
	//selfnumber 맞으면 return true
	int temp = num;
	while (num != 0) {
		temp += num % 10;
		num = num / 10;
	}
	selfnumbers[temp] = true;
}
int main() {

	//1부터 10,000까지 selfnumber로 보내기(loop)
	for (int i = 1; i <= SIZE; i++) {
		selfnumber(i);
	}
	for (int k = 1; k < SIZE+1; k++) {
		if (selfnumbers[k] == false) {
			cout << k << endl;
		}
	}
}
