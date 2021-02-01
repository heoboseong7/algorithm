#include <bits/stdc++.h>

using namespace std;

int input, ans, n;

int main() {
  for(int i = 0; i < 9; i++) {
    scanf("%d", &input);
    if(ans < input) {
      ans = input;
      n = i + 1;
    }
  }
  printf("%d\n%d", ans, n);
  return 0;
}
