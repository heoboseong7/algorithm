#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[100001];
int coin[100001];


int main() {
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++) {
		scanf("%d", coin + i);
	}
	
	dp[0] = 1;
	
	for(int i = 0; i < n; i++) {
		for(int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	
	printf("%d", dp[k]);
	
	return 0;
}