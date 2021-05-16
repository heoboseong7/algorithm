#include <bits/stdc++.h>

using namespace std;

string s;
int T, R;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T;
  while(T--) {
    cin >> R >> s;
    for(int i = 0; i < (int)s.length(); i++) {
      for(int j = 0; j < R; j++)
        cout << s[i];
    }
    cout << '\n';
  }
  return 0;
}
