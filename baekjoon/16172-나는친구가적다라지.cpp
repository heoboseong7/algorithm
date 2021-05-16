#include <bits/stdc++.h>

using namespace std;

string s, temps, ans;
char str[210000];

vector<int> findfail(string w) {
  vector<int> fail;
  fail.push_back(0);
  for(int i = 1, j = 0; i < w.length(); i++) {
    while(j > 0 && w[i] != w[j]) {
      j = fail[j - 1];
    }
    if(w[i] == w[j]) {
      fail.push_back(++j);
    }
    else {
      fail.push_back(0);
    }
  }
  return fail;
}

bool kmp(string s, string w) {
  int m = s.length();
  int n = w.length();
  vector<int> fail = findfail(w);

  /*
  for(int i = 0; i < fail.size(); i++) {
    cout << fail[i] << endl;
  }
  */

  for(int i = 0, j = 0; i < m; i++) {
    while(j > 0 && s[i] != w[j]) {
      j = fail[j - 1];
    }
    if(s[i] == w[j]) {
      if(j == n - 1) {
        return true;
      }
      else {
        j++;
      }
    }
  }
  return false;
}

int main() {
    cin >> temps;
    cin >> ans;
    int len = temps.length();
    int end = 0;
    for(int i = 0; i < len; i++) {
      if(!(47 < temps[i] && temps[i] < 58)) {
        str[end++] = temps[i];
      }
    }
    str[end] = '\0';
    if(kmp((string)str, ans)) {
      printf("1");
    }
    else {
      printf("0");
    }
    return 0;
}
