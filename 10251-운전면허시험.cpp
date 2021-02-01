#include <iostream>
#define down 1
#define right 2
using namespace std;

int m, n, l, g;
int map[101][101];
int gas[101][101];
int dir[101][101];
int dirchange[101][101];
int dp[101][101];

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n >> l >> g;
		for (int T = 1; T <= m + n; T++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (i == 0 && j == 0)
						continue;

					dp[0][0] = 0;

					if (i == 0) {
						dp[i][j] = dp[i][j - 1] + gas[0][j - 1];
						dir[i][j] = right;
					}
					else if (j == 0) {
						dp[i][j] = dp[i - 1][j] + gas[i - 1][0];
						dir[i][j] = down;
					}
					else {
						int tempA, tempB;
						if (dir[i - 1][j] == down) {
							tempA = dp[i - 1][j] + gas[i - 1][j];
						}
						else if (T - dirchange[i][j] > 0){
							tempA = dp[i - 1][j] + gas[i - 1][j];
							dirchange[i][j]++;
						}
						else {
							tempA = -1;
						}

						if ()
					}
				}
			}
		}
	}

	return 0;
}
