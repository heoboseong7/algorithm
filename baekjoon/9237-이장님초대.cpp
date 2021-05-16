#include <bits/stdc++.h>

using namespace std;

int n, temp;
int ans = 0;
vector<int> t;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    t.push_back(temp);
  }
  sort(t.begin(), t.end(), greater<int>());

  for(int i = 1; i <= n; i++) {
    ans = ans > i + 1 + t[i - 1] ? ans : i + 1 + t[i - 1];
  }
  cout << ans;
  return 0;
}
