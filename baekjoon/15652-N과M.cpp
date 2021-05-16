#include <bits/stdc++.h>

using namespace std;

int n, m;

inline void func(int a, int b) {
  if(b > m)
    return;
  for(int i = a; i <= n; i++) {
    if(b == m) {
      cout << i << '\n';
    }
    else {
      cout << i << ' ';
      func(i, b + 1);
    }
  }
}

int main() {
  cin >> n >> m;

  func(1, 1);

  return 0;
}
