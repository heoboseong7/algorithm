#include <bits/stdc++.h>

using namespace std;

int n;
int dp[100001];
//int dp[100001];
int MAX = -1000000000;
vector<int> v;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", dp + i);
  }
  MAX = dp[0];
  for(int i = 1; i < n; i++) {
    if(dp[i] + dp[i - 1] > 0 && dp[i - 1] > 0) {
      dp[i] += dp[i - 1];
    }
    MAX = dp[i] > MAX ? dp[i] : MAX;
  }

  printf("%d", MAX);
  return 0;
}
