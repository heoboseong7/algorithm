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
    if(s.find(ans) != string::npos) {
      printf("1");
    }
    else {
      printf("0");
    }
    return 0;
}
