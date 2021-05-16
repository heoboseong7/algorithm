#include <bits/stdc++.h>

using namespace std;

int ans[26];
string s;
int main() {
  memset(ans, -1, 26 * 4);

  cin >> s;
  for(int i = 0; i < s.size(); i++) {
    if(ans[(int)s[i] - 97] == -1)
      ans[(int)s[i] - 97] = i;
  }

  for(int i = 0; i < 26; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
