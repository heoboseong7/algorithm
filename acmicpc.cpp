#include <bits/stdc++.h>

using namespace std;

int n, i;
int mini = 0;
string str;
bool check[10000];
int main() {
  cin >> n;
  cin >> str;
  while(!check[i]) {
    i = 0;
    for(int k = 0; k < str.size(); k++) {
      i += pow((int)(str[k] - 48), 2);
    }
    if(i == 1) {
      cout << "Happynumber";
      return 0;
    }
    

  }
  cout << "Unhappynumber";
  return 0;
}
