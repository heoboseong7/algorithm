#include <bits/stdc++.h>
#define MAX 1000000009
using namespace std;

long long int dp[100001];
long long int n, c, k;
long long int ans = 0;
int main() {
  dp[0] = 0; dp[1] = 1;
  for(int i = 2; i <= 100000; i++) {
    dp[i] = (dp[i - 1] * 2) % MAX;
  }
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf("%d %d", &c, &k);
    ans = (ans + c * k * dp[k]) % MAX;
  }

  printf("%lld", ans);

  return 0;
}
