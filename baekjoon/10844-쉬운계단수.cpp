// 10억 쓸때 좀 잘 쓰자 ..
#include <bits/stdc++.h>

using namespace std;

int n;
long long int sum;
long long int dp[100][10];

int main() {
  scanf("%d", &n);

  for(int i = 1; i < 10; i++) {
    dp[0][i] = 1;
  }
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < 10; j++) {
      if(j == 0) {
        dp[i][j] += dp[i - 1][1] % 1000000000;
      }
      else if(j == 9) {
        dp[i][j] = dp[i - 1][8] % 1000000000;
      }
      else {
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
      }
    }
  }

  for(int i = 0; i < 10; i++) {
    sum = (sum + dp[n - 1][i]) % 1000000000;
  }
  printf("%lld", sum % 1000000000);

  return 0;
}
