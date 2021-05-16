#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  int ans = 0;
  scanf("%d", &n);

  for(int i = 1; i <= n; i++) {
    int gap = -100, before = 987654321;
    for(int j = i; j > 0;) {
      if(gap == -100) {
        gap = -200;
      }
      else if(gap == -200 || gap == before - j % 10) {
        gap = before - j % 10;
      }
      else break;
      before = j % 10;
      j /= 10;
      if(j == 0) ans++;
    }
  }
  printf("%d", ans);

  return 0;
}
