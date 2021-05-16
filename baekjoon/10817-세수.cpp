#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v;
  for(int i = 0; i < 3; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  cout << v[1];

  return 0;
}
