#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, x;
  cin >> n >> x;
  for(int i = 0; i < n; i++) {
    int  temp;
    cin >> temp;
    if(temp < x) {
      cout << temp << ' ';
    }
  }

  return 0;
}
