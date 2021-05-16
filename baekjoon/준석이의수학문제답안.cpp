#include <bits/stdc++.h>

using namespace std;

int T, n, ans;

int sum(int i) {
  return i * (n / i) * (n / i + 1) / 2;
}

int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    ans = 0;
    for(int i = 3; i <= n; i += 3)
      ans += i;
    for(int i = 7; i <= n; i += 7)
      if(i % 3 != 0) ans += i;
    printf("%d\n", ans);

    //printf("%d\n", sum(3) - sum(21) + sum(7));
  }
  return 0;
}
