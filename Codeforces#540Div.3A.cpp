#include <bits/stdc++.h>

using namespace std;

int q;
long long int n, a, b;

int main() {
  scanf("%d", &q);

  for(int i = 0; i < q; i++) {
    scanf("%lld %lld %lld", &n, &a, &b);
    if(2 * a <= b) {
      printf("%lld\n", a * n);
    }
    else {
      printf("%lld\n", (n / 2 * b + (n % 2) * a));
    }
  }

  return 0;
}
