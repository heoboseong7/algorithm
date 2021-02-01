#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v;

  int temp, n;
  cin >> n;
  v.push_back(1);
  v.push_back(1);

  for(int i = 2; i < n; i++) {
    v[i] = v[i - 1] + v[i - 2];
  }

  cout << v[n];

  return 0;
}
