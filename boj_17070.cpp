#include <iostream>
#include <vector>
using namespace std;

int n, cnt=0;
vector<vector<int> > home(17, vector<int>(17));

void dp(int a1, int b1, int a2, int b2) {
	if (a2 == n-1 && b2 == n-1 && home[a2][b2]!=1) {
		cnt++;
	}
	else {
		if (a2<n && b2<n && home[a2][b2] != 1) {
			int absA = abs(a1 - a2);
			int absB = abs(b1 - b2);

			if (absA == 0 && absB == 1) {
				dp(a2, b2, a2, b2 + 1);
				if(a2+1 < n && b2+1 < n && home[a2+1][b2]!=1 && home[a2][b2+1] != 1) dp(a2, b2, a2 + 1, b2 + 1);

			}
			else if (absA == 1 && absB == 0) {
				dp(a2, b2, a2 + 1, b2);
				if (a2 + 1 < n && b2 + 1 && home[a2+1][b2] != 1 && home[a2][b2+1] != 1) dp(a2, b2, a2 + 1, b2 + 1);
			}
			else if (absA == 1 && absB == 1) {
				dp(a2, b2, a2 + 1, b2);
				dp(a2, b2, a2, b2 + 1);
				if (a2 + 1 < n && b2 + 1 && home[a2+1][b2] != 1 && home[a2][b2+1] != 1) dp(a2, b2, a2 + 1, b2 + 1);
			}
		}
		else {
			return;
		}


	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> home[i][j];
		}
	}

	dp(0, 0, 0, 1);

	cout << cnt;

	return 0;


}
