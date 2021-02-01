#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, ans = -1;
  vector<int> a;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    a.push_back(temp);
  }

  for(int i = 0; i < n; i++) {
    int before = a[i], cnt = 1;
    for(int j = i + 1; j < n; j++) {
      if(before < a[j]) {
        before = a[j];
        cnt++;
      }
    }
    ans = ans < cnt ? cnt : ans;
  }

  cout << ans;

  return 0;
}
