#include <bits/stdc++.h>

using namespace std;

int t, a, b, c;
int money;

int main() {
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> money;
    a = money / 25; money %= 25;
    b = money / 10; money %= 10;
    c = money / 5; money %= 5;
    cout << a << ' ' << b << ' ' << c << ' ' << money << '\n';
  }

  return 0;
}
