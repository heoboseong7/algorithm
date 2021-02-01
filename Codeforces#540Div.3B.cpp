#include <bits/stdc++.h>

using namespace std;

int n, even, odd, ans;
int a[1000001];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if(i % 2) {
      even += a[i];
    }
    else {
      odd += a[i];
    }
  }
  even -= a[1];

  for(int i = 1; i <= n; i++) {
    if(odd == even) ans++;
    if(i % 2) {
      odd += a[i] - a[i + 1];
    }
    else {
      even += a[i] - a[i + 1];
    }
}

 cout << ans;
  return 0;
}
