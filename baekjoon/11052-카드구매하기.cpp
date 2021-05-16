#include <bits/stdc++.h>

using namespace std;

int n, ans;
int tempans;
int p[1001];
int dp[1001];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", p + i);
  }

  ans = p[0] * n;
  dp[1] = p[0];
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j < i; j++) {
      dp[i] = dp[j] + dp[i - j] > dp[i] ? dp[j] + dp[i - j] : dp[i];
    }
    dp[i] = dp[i] > p[i - 1] ? dp[i] : p[i - 1];
  }

  printf("%d", dp[n]);
  return 0;
}
