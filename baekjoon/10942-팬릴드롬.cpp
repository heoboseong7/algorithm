#include <bits/stdc++.h>

using namespace std;

int arr[2001];
int dp[2001][2001];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }

  for(int i = 0; i < n; i++) {
    dp[i][i] = 1;
  }

  for(int i = 0; i < n - 1; i++) {
    if(arr[i] == arr[i + 1]) {
      dp[i][i + 1] = 1;
    }
  }

  for(int i = 2; i < n; i++) {
    for(int j = 0; j < n - i; j++) {
      if(dp[j + 1][j + i - 1] == 1 && arr[j] == arr[j + i]) {
        dp[j][j + i] = 1;
      }
    }
  }

  int m, s, e;
  scanf("%d", &m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &s, &e);
    if(dp[s - 1][e - 1] == 1) {
      printf("1\n");
    }
    else {
      printf("0\n");
    }
  }
  return 0;
}
