#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  while(1) {
    scanf("%d %d", &a, &b);
    if(a || b)
      printf("%d\n", a + b);
    else
      break;
  }
  return 0;
}
