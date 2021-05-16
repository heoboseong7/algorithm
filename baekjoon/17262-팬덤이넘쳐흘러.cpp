#include <bits/stdc++.h>

using namespace std;

int n, t[100001], s, e, ans = 0, d = 0;
int a, b;
int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
      scanf("%d %d", &s, &e);
      if(t[s] > e || !t[s])
        t[s] = e;
    }
    for(int i = 1; i < 100001; i++) {
      if(t[i]) {
        b = i;
        if(d && d <= i && !a)
          a = d;

        d = max(t[i], d);
      }
    }
    if(a)
      printf("%d", b - a);
    else
      printf("0");
    return 0;
}
