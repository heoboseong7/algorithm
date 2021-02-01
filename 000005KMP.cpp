#include <bits/stdc++.h>

using namespace std;

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

  for(int i = 0, j = 0; i < n; i++) {
    while(j > 0 && s[i] != w[j]) {
      j = fail[j - 1];
    }
    if(s[i] == w[j]) {
      if(j == m - 1) {
        return true;
      }
      else {
        j++;
      }
    }
  }
  return false;
}
