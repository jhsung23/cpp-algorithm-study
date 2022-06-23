#include <iostream>
#include <string>
using namespace std;
int main()
{
	// 1: 나올리없음? --2초
	// 2: ABC(0,1,2) --3초
	// 3: DEF(3,4,5) --4초
	// 4: GHI(6,7,8) --5초
	// 5: JKL(9,10,11) --6초
	// 6: MNO(12,13,14) --7초
	// 7: PQRS(15,16,17,18) --8초
	// 8: TUV(19,20,21) --9초
	// 9: WXYZ(22,23,24,25) --10초

	int sec = 0;
	string word;
	cin >> word;

	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == 'A' | word[i] == 'B' | word[i] == 'C')
			sec += 3;
		else if (word[i] == 'F' | word[i] == 'D' | word[i] == 'E')
			sec += 4;
		else if (word[i] == 'G' | word[i] == 'H' | word[i] == 'I')
			sec += 5;
		else if (word[i] == 'J' | word[i] == 'K' | word[i] == 'L')
			sec += 6;
		else if (word[i] == 'M' | word[i] == 'N' | word[i] == 'O')
			sec += 7;
		else if (word[i] == 'P' | word[i] == 'Q' | word[i] == 'R' | word[i] == 'S')
			sec += 8;
		else if (word[i] == 'T' | word[i] == 'U' | word[i] == 'V')
			sec += 9;
		else if (word[i] == 'W' | word[i] == 'X' | word[i] == 'Y' | word[i] == 'Z')
			sec += 10;
	}
	cout << sec << endl;
}
