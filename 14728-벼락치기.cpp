#include <bits/stdc++.h>

using namespace std;

int dp[10100];
int k[1001];
int s[1001];
bool check[10101];

int main() {
  int n, T;
  scanf("%d %d", &n, &T);

  for(int i = 0; i < n; i++) {
    scanf("%d %d", k + i, s + i);
  }

  for(int i = 0; i < n; i++) {
    memset(check, true, 10101);
    for(int j = 0; j + k[i] < T + 1; j++) {
      if(check[j]) {
        dp[j + k[i]] = max(dp[j + k[i]], dp[j] + s[i]);
        if(dp[j + k[i]] == dp[j] + s[i])  check[j + k[i]] = false;
      }
    }
  }
  int ans = -987654321;
  for(int i = 0; i < T + 1; i++) {
    ans = max(ans, dp[i]);
  }
  printf("%d", ans);
  return 0;
}
