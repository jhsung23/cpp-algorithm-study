#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	int count[10001] = { 0 };
	for (int i = 0; i < t; i++) {
		int num;
		scanf("%d", &num);
		count[num] += 1;
	}
	for (int i = 1; i < 10001; i++) {
		if (count[i] == 0) continue;
		else {
			for (int j = 0; j < count[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
}
