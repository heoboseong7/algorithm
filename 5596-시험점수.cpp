#include <bits/stdc++.h>

using namespace std;

int main() {
  int input, a = 0, b = 0;

  for(int i = 0; i < 4; i++) {
    cin >> input;
    a += input;
  }

  for(int i = 0; i < 4; i++) {
    cin >> input;
    b += input;
  }
  cout << max(a, b);

  return 0;
}
