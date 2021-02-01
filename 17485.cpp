#include <bits/stdc++.h>
using namespace std;

#define MIN(a, b) ((a < b) ? a : b)
#define MIN3(a, b, c) MIN(a, MIN(b, c))

int dp[1001][1001];
int before[1001][1001];
int input[1001][1001];
int n, m;


int main() {
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < 1001; i++) {
		memset(dp[i], 1000001, 1001);
		memset(input[i], 1000001, 1001);
	}
	
	
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &input[i][j]);
	
	for(int i = 1; i <= m; i++) {
		before[1][i] = 4;
		dp[1][i] = input[1][i];
	}
	// 왼쪽 1 중앙 2 오른쪽 3 중복이 있는경우 4
	for(int i = 1; i < n; i++)
		for(int j = 1; j <= m; j++) {
			if(before[i][j] == 1) {
				if(dp[i + 1][j] == dp[i][j] + input[i + 1][j]) before[i + 1][j] = 4;
				else before[i + 1][j] = dp[i + 1][j] < dp[i][j] + input[i + 1][j] ? before[i + 1][j] : 2;
				if(dp[i + 1][j + 1] == dp[i][j] + input[i + 1][j + 1]) before[i + 1][j + 1] = 4;
				else before[i + 1][j + 1] = dp[i + 1][j + 1] < dp[i][j] + input[i + 1][j + 1] ? before[i + 1][j] : 3;
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + input[i + 1][j]);
				if(j < m) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + input[i + 1][j + 1]);
			}
			else if(before[i][j] == 2) {
				if(dp[i + 1][j - 1] == dp[i][j] + input[i + 1][j - 1]) before[i + 1][j - 1] = 4;
				else before[i + 1][j - 1] = dp[i + 1][j - 1] < dp[i][j] + input[i + 1][j - 1] ? before[i + 1][j - 1] : 1;
				if(dp[i + 1][j + 1] == dp[i][j] + input[i + 1][j + 1]) before[i + 1][j + 1] = 4;
				else before[i + 1][j + 1] = dp[i + 1][j + 1] < dp[i][j] + input[i + 1][j + 1] ? before[i + 1][j + 1] : 3;
				if(j > 1)dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + input[i + 1][j - 1]);
				if(j < m)dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + input[i + 1][j + 1]);
			}
			else if(before[i][j] == 3) {
				if(dp[i + 1][j] == dp[i][j] + input[i + 1][j]) before[i + 1][j] = 4;
				else before[i + 1][j] = dp[i + 1][j] < dp[i][j] + input[i + 1][j] ? before[i + 1][j] : 2;
				if(dp[i + 1][j - 1] == dp[i][j] + input[i + 1][j - 1]) before[i + 1][j - 1] = 4;
				else before[i + 1][j - 1] = dp[i + 1][j - 1] < dp[i][j] + input[i + 1][j - 1] ? before[i + 1][j - 1] : 1;
				if(j > 2)dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + input[i + 1][j - 1]);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + input[i + 1][j]);
			}
			else {
				if(dp[i + 1][j - 1] == dp[i][j] + input[i + 1][j - 1]) before[i + 1][j - 1] = 4;
				else before[i + 1][j - 1] = dp[i + 1][j - 1] < dp[i][j] + input[i + 1][j - 1] ? before[i + 1][j - 1] : 1;
				if(dp[i + 1][j] == dp[i][j] + input[i + 1][j]) before[i + 1][j] = 4;
				else before[i + 1][j] = dp[i + 1][j] < dp[i][j] + input[i + 1][j] ? before[i + 1][j] : 2;
				if(dp[i + 1][j + 1] == dp[i][j] + input[i + 1][j + 1]) before[i + 1][j + 1] = 4;
				else before[i + 1][j + 1] = dp[i + 1][j + 1] < dp[i][j] + input[i + 1][j + 1] ? before[i + 1][j + 1] : 3;
				if(j > 1)dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + input[i + 1][j - 1]);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + input[i + 1][j]);
				if(j < m)dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + input[i + 1][j + 1]);
			}
		}
							   
	int ans = 987654321;
	for(int i = 1; i <= m; i++)
		ans = min(ans, dp[n][i]);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			printf("%d ", dp[i][j]);
	printf("\n");
	}
	printf("%d", ans);
							   
	return 0;
	
}