#include <bits/stdc++.h>

using namespace std;

string s, temps, ans;

int main() {
    cin >> temps;
    cin >> ans;
    for(int i = 0; i < temps.length(); i++) {
      if(!(47 < temps[i] && temps[i] < 58)) {
        s = s + temps[i];
      }
    }

    for(int i = 0; i < s.length(); i++) {
      if(s[i] == ans[0]) {
        for(int j = 1; j < ans.length(); j++) {
          if(s[i + j] != ans[j]) {
            i += j - 1;
            break;
          }
          if(j == ans.length() - 1) {
            printf("1");
            return 0;
          }
        }
      }
    }
    printf("0");
    return 0;
}
