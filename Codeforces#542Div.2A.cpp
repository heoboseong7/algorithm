#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, neg = 0, pos = 0, m;
  vector<int> v;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int input;
    cin >> input;
    if(input > 0) pos++;
    else if(input < 0) neg++;
  }

  if(n % 2 == 0) m = n / 2;
  else m = n / 2 + 1;

  if(m <= pos)
    cout << 1;
  else if(m <= neg)
    cout << -1;
  else
    cout << 0;
  return 0;
}
